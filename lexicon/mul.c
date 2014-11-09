/*
** mul.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:03 2014 brendan rius
** Last update Sun Nov  9 23:08:46 2014 Louis Person
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
#include "karatsuba_split.h"
#include "operators.h"

void	action_mul_get_one(t_base *base, t_token *token)
{
  token->string_value = &base->string[0];
  token->dynamic = FALSE;
  token->size = 1;
  token->sign = POSITIVE;
}

t_rcode		simple_mul(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  int		carry;
  int		cursor;
  int		tmp;

  if (n2->size > n1->size)
    reorder_tokens(&n1, &n2);
  if (n2->size == 1 && n2->string_value[0] == base->string[0])
    {
      action_mul_get_one(base, res);
      return (OK);
    }
  if ((malloc_token_dynamically(res, n1->size + 1)) != OK)
    return (COULD_NOT_MALLOC);
  res->string_value[0] = base->string[0];
  carry = 0;
  cursor = n1->size - 1;
  while (cursor >= 0 || carry)
    {
      tmp = (get_value_at_index(base, n1->string_value, cursor) *
	     get_value_at_index(base, n2->string_value, 0) + carry);
      carry = tmp / base->size;
      res->string_value[cursor-- + 1] = base->string[tmp % base->size];
    }
  clean_number_str(base, res);
  return (OK);
}

t_rcode		action_mul(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_rcode	ret;
  int		m2;
  t_karat_coeff	coefficients;
  t_token	*tmp;
  t_delimiters	delimiters;

  if ((n1->sign == NEGATIVE) ^ (n2->sign == NEGATIVE))
    res->sign = NEGATIVE;
  if (n1->size == 1 || n2->size == 1)
    return (simple_mul(base, n1, n2, res));
  if ((ret = malloc_token_dynamically(res, n1->size + n2->size)) != OK)
    return (ret);
  my_memset(res->string_value, base->string[0], res->size);
  m2 = my_max(n1->size, n2->size) / 2;
  split_tokens(n1, n2, &delimiters, base);
  compute_z0(base, &delimiters, m2, &coefficients);
  compute_z1(base, &delimiters, &coefficients);
  compute_z2(base, &delimiters, m2, &coefficients);
  bm_new_token(&tmp);
  action_add(base, coefficients.z0, coefficients.z1, tmp);
  action_add(base, tmp, coefficients.z2, res);
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
