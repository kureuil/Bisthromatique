/*
** mul.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:03 2014 brendan rius
** Last update Sat Nov  8 12:38:58 2014 Louis Person
*/

#include <stdlib.h>
#include <unistd.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "my.h"
#include "boolean.h"
#include "karatsuba_utils.h"
#include "operators.h"

t_rcode		simple_mul(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  int		carry;
  int		cursor;
  int		tmp;
  t_rcode	ret;

  if (n2->size > n1->size)
    reorder_tokens(&n1, &n2);
  if ((ret = malloc_token_dynamically(res, n1->size + 1)) != OK)
    return (ret);
  res->string_value[0] = base->string[0];
  carry = 0;
  cursor = n1->size - 1;
  while (cursor >= 0 || carry)
    {
      tmp = (get_value_at_index(base, n1->string_value, cursor) *
	     get_value_at_index(base, n2->string_value, 0) +
	     carry);
      carry = tmp / base->size;
      res->string_value[cursor + 1] = base->string[tmp % base->size];
      cursor--;
    }
  clean_number_str(base, res);
  return (OK);
}

t_rcode		split_tokens(t_token *n1,
			     t_token *n2,
			     t_delimiters *delimiters,
			     t_base *base)
{
  t_token	*a;
  t_token	*b;
  t_token	*c;
  t_token	*d;
  t_rcode	ret;

  if ((ret = bm_new_token(&a)) != OK ||
      (ret = bm_new_token(&b)) != OK ||
      (ret = bm_new_token(&c)) != OK ||
      (ret = bm_new_token(&d)) != OK)
    return (ret);
  delimiters->a = a;
  delimiters->b = b;
  delimiters->c = c;
  delimiters->d = d;
  if ((ret = split_token(n1, n2, delimiters)) != OK)
    return (ret);
  clean_number_str(base, delimiters->a);
  clean_number_str(base, delimiters->b);
  clean_number_str(base, delimiters->c);
  clean_number_str(base, delimiters->d);
  return (OK);
}

t_rcode		compute_z0(t_base *base,
			   t_delimiters *delimiters,
			   t_token **z0)
{
  t_rcode	ret;

  if ((ret = bm_new_token(z0)) != OK)
    return (ret);
  return (action_mul(base, delimiters->a, delimiters->c, *z0));
}

t_rcode		compute_z1(t_base *base,
			   t_delimiters *delimiters,
			   t_token **z1)
{
  t_rcode	ret;

  if ((ret = bm_new_token(z1)) != OK)
    return (ret);
  return (action_mul(base, delimiters->b, delimiters->d, *z1));
}

t_rcode		compute_z2(t_base *base,
			   t_delimiters *delimiters,
			   t_token *z0,
			   t_token *z1,
			   t_token **z2)
{
  t_rcode	ret;
  t_token	*apb;
  t_token	*cpd;
  t_token	*z2_tmp;
  t_token	*z2_tmp2;

  if ((ret = bm_new_token(z2)) != OK ||
      (ret = bm_new_token(&apb)) != OK ||
      (ret = bm_new_token(&cpd)) != OK ||
      (ret = bm_new_token(&z2_tmp)) != OK ||
      (ret = bm_new_token(&z2_tmp2)) != OK)
    return (ret);
  action_add(base, delimiters->a, delimiters->b, apb);
  action_add(base, delimiters->c, delimiters->d, cpd);
  action_mul(base, apb, cpd, z2_tmp);
  action_sub_compute(base, z2_tmp, z0, z2_tmp2);
  clean_number_str(base, z2_tmp2);
  action_sub_compute(base, z2_tmp2, z1, *z2);
  clean_number_str(base, *z2);
  bm_free_token(z2_tmp);
  bm_free_token(z2_tmp2);
  return (OK);
}

t_rcode		action_karatsuba(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_rcode	ret;
  int		m;
  int		m2;
  t_token	*z0;
  t_token	*z1;
  t_token	*z2;
  t_token	*z0_padded;
  t_token	*z2_padded;
  t_token	*tmp;
  t_delimiters	delimiters;

  if ((n1->sign == NEGATIVE) ^ (n2->sign == NEGATIVE))
    res->sign = NEGATIVE;
  if (n1->size == 1 || n2->size == 1)
    return (simple_mul(base, n1, n2, res));
  if ((ret = malloc_token_dynamically(res, n1->size + n2->size)) != OK)
    return (ret);
  my_memset(res->string_value, base->string[0], res->size);
  m = my_max(n1->size, n2->size);
  m2 = m / 2;
  split_tokens(n1, n2, &delimiters, base);
  compute_z0(base, &delimiters, &z0);
  compute_z1(base, &delimiters, &z1);
  compute_z2(base, &delimiters, z0, z1, &z2);
  bm_new_token(&z0_padded);
  bm_new_token(&z2_padded);
  pad(z0, base, m2 * 2, z0_padded);
  clean_number_str(base, z0_padded);
  pad(z2, base, m2, z2_padded);
  clean_number_str(base, z2_padded);
  bm_new_token(&tmp);
  action_add(base, z0_padded, z1, tmp);
  action_add(base, tmp, z2_padded, res);
  return (OK);
}

#include <stdint.h>
#include <stdio.h>

t_rcode		action_mul_compute(t_base *base,
				   t_token *n1,
				   t_token *n2,
				   t_token **res)
{
  t_token	*tmp;
  t_token	*minus;
  t_rcode	ret;
  
  bm_new_token(&tmp);
  bm_new_token(&minus);
  if ((ret = malloc_token_dynamically(*res, 1)) != OK ||
      (ret = malloc_token_dynamically(minus, 1)) != OK)
    return (ret);
  (*(res))->string_value[0] = base->string[0];
  minus->string_value[0] = base->string[1];
  while (n2->size >= 1 && n2->string_value[0] != base->string[0])
    {
      bm_free_token(tmp);
      bm_new_token(&tmp);
      if ((ret = malloc_token_dynamically(tmp, 1)) != OK)
	return (ret);
      tmp->string_value[0] = base->string[0];
      reorder_tokens(&tmp, res);
      printf("action_mul_compute: %lu\n", (uintptr_t) *res);
      action_add_compute(base, n1, tmp, *res);
      clean_number_str(base, *res);
      action_sub_compute(base, n2, minus, tmp);
      clean_number_str(base, tmp);
      reorder_tokens(&tmp, &n2);
    }
  bm_free_token(tmp);
  bm_free_token(minus);
  printf("action_mul_compute: %lu\n", (uintptr_t) *res);
  bm_print_token(*res);
  return (OK);
}

t_rcode		action_mul(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_rcode	ret;
  t_token	*tmp;

  bm_new_token(&tmp);
  if ((n1->sign == NEGATIVE) ^ (n2->sign == NEGATIVE))
    res->sign = NEGATIVE;
  if (my_strcmp(n1->string_value, n2->string_value) > 0)
    reorder_tokens(&n1, &n2);
  printf("action_mul1: %lu\n", (uintptr_t) res->string_value);
  if ((ret = action_mul_compute(base, n1, n2, &tmp)) != OK)
    return (ret);
  res->string_value = tmp->string_value;
  res->real_address = tmp->real_address;
  res->size = tmp->size;
  tmp->dynamic = FALSE;
  bm_free_token(tmp);
  printf("action_mul2: %lu\n", (uintptr_t) res->string_value);
  printf("action_mul2: %s\n", res->string_value);
  bm_print_token(res);
  return (OK);
}

t_rcode	extract_mul(char *c, t_token *token)
{
  if (!c)
    return (NULL_REFERENCE);
  token->type = OPERATOR;
  token->operator.action = &action_mul;
  token->operator.precedence = 10;
  token->size = 1;
  return (OK);
}
