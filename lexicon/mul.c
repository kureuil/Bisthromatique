/*
** mul.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:03 2014 brendan rius
** Last update Thu Nov  6 15:16:19 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "my.h"
#include "boolean.h"
#include "karatsuba_utils.h"

t_rcode	simple_mul(t_base *base,
		   t_token *n1,
		   t_token *n2,
		   t_token *res)
{
  int	carry;
  int	cursor;
  int	tmp;

  if (n2->size > n1->size)
    reorder_tokens(&n1, &n2);
  res->size = n1->size + 1;
  if (!(res->string_value = res->real_address = malloc(res->size)))
    return (COULD_NOT_MALLOC);
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
  bm_free_token(n1);
  bm_free_token(n2);
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

  if (n1->size == 1 || n2->size == 1)
    return (simple_mul(base, n1, n2, res));
  m2 = my_max(n1->size, n2->size) / 2;
  high1 = low1 = high2 = low2 = a = b = z0 = z1 = z2 = NULL;
  split_token(n1, m2, high1, low1);
  split_token(n2, m2, high2, low2);
  action_add(base, low1, high1, a);
  action_add(base, low2, high2, b);
  action_mul(base, low1, low2, z0);
  action_mul(base, a, b, z1);
  action_mul(base, high1, high2, z2);
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
