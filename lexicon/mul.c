/*
** mul.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:03 2014 brendan rius
** Last update Fri Nov  7 17:08:14 2014 Louis Person
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
  /*  bm_free_token(n1);
      bm_free_token(n2);*/
  return (OK);
}

t_rcode		action_mul(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  int		m2;
  t_token	*high1;
  t_token	*low1;
  t_token	*high2;
  t_token	*low2;
  t_token	*z0;
  t_token	*z1;
  t_token	*z2;
  t_token	*a;
  t_token	*b;
  t_token	*z1z2z0;
  t_token	*z1z2z0_t;
  t_token	*pre_final;
  t_token	*b1;
  t_token	*b2;
  t_token	*rr1;
  t_token	*rr2;
  t_rcode	ret;

  if ((n1->sign == NEGATIVE) ^ (n2->sign == NEGATIVE))
    res->sign = NEGATIVE;
  if (n1->size == 1 || n2->size == 1)
    return (simple_mul(base, n1, n2, res));
  if ((ret = malloc_token_dynamically(res, n1->size + n2->size)) != OK)
    return (ret);
  my_memset(res->string_value, base->string[0], res->size);
  m2 = my_max(n1->size, n2->size) / 2;

  high1 = low1 = high2 = low2 = a = b = z0 = z1 = z2 = NULL;
  rr1 = rr2 = b1 = b2 = pre_final = z1z2z0 = z1z2z0_t = NULL;

  bm_new_token(&a);
  bm_new_token(&b);
  bm_new_token(&z0);
  bm_new_token(&z1);
  bm_new_token(&z2);
  bm_new_token(&b1);
  bm_new_token(&b2);
  bm_new_token(&z1z2z0);
  bm_new_token(&z1z2z0_t);
  bm_new_token(&rr1);
  bm_new_token(&rr2);
  bm_new_token(&pre_final);
  bm_new_token(&low1);
  bm_new_token(&low2);
  bm_new_token(&high1);
  bm_new_token(&high2);

  split_token(n1, m2, high1, low1);
  split_token(n2, m2, high2, low2);
  clean_number_str(base, low1);
  clean_number_str(base, low2);
  clean_number_str(base, high1);
  clean_number_str(base, high2);

  /* Z0 */
  action_mul(base, low1, low2, z0);

  /* Z1 */
  action_add_compute(base, low1, high1, a);
  clean_number_str(base, a);
  action_add_compute(base, low2, high2, b);
  clean_number_str(base, b);
  action_mul(base, a, b, z1);

  /* Z2 */
  action_mul(base, high1, high2, z2);

  pow_base(base, 2 * m2, b1);
  pow_base(base, m2, b2);

  /* z1 - z2 - z0 */
  action_sub_compute(base, z1, z2, z1z2z0_t);
  clean_number_str(base, z1z2z0_t);
  action_sub_compute(base, z1z2z0_t, z0, z1z2z0);
  clean_number_str(base, z1z2z0);

  /* z2 * b1 */
  action_mul(base, z2, b1, rr1);

  /* (z1 - z2 - z0) * b2 */
  action_mul(base, z1z2z0, b2, rr2);

  /* (z2 * b1) + ((z1 - z2 - z0) * b2) */
  action_add_compute(base, rr1, rr2, pre_final);
  clean_number_str(base, pre_final);

  action_add(base, pre_final, z0, res);

  bm_free_token(a);
  bm_free_token(b);
  bm_free_token(z1);
  bm_free_token(z2);
  bm_free_token(b1);
  bm_free_token(b2);
  bm_free_token(z1z2z0);
  bm_free_token(z1z2z0_t);
  bm_free_token(rr1);
  bm_free_token(rr2);
  bm_free_token(low1);
  bm_free_token(low2);
  bm_free_token(high1);
  bm_free_token(high2);

  clean_number_str(base, res);
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
