/*
** sub.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:36 2014 brendan rius
** Last update Wed Nov  5 18:22:56 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "operators.h"
#include "my.h"

t_rcode		action_sub_compute(t_base *base,
				   t_token *n1,
				   t_token *n2,
				   t_token *res)
{
  int           carry;
  int           cursor;
  int           tmp;
  int           shift;
  t_rcode	ret;

  if (my_strcmp_base(n1, n2, base) < 0)
    {
        reorder_tokens(&n1, &n2);
        res->sign = NEGATIVE;
    }
  if ((ret = malloc_token_dynamically(res, n1->size + 1)) != OK)
    return (ret);
  carry = 0;
  cursor = n1->size - 1;
  shift = n1->size - n2->size;
  while (cursor >= 0 || carry)
  {
    tmp = (get_value_at_index(base, n1->string_value, cursor) -
        (get_value_at_index(base, n2->string_value, cursor - shift) + carry));
    carry = tmp < 0 ? 1 : 0;
    tmp = tmp < 0 ? base->size + tmp : tmp;
    res->string_value[cursor-- + 1] = base->string[tmp % base->size];
  }
  return (OK);
}

t_rcode		action_sub(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_rcode	ret;

  if (n1->sign == NEGATIVE && n2->sign == POSITIVE)
    {
      n1->sign = POSITIVE;
      if ((ret = action_add(base, n1, n2, res)) != OK)
	return (ret);
      res->sign = NEGATIVE;
      return (OK);
    }
  if ((n1->sign == NEGATIVE && n2->sign == NEGATIVE) ||
      (n1->sign == POSITIVE && n2->sign == NEGATIVE))
    {
      n2->sign = POSITIVE;
      if ((ret = action_add(base, n1, n2, res)) != OK)
	return (ret);
      return (OK);
    }
  if ((ret = action_sub_compute(base, n1, n2, res)) != OK)
    return (ret);
  clean_number_str(base, res);
  bm_free_token(n1);
  bm_free_token(n2);
  return (OK);
}

/*
** We could speed this up by avoiding copying n into res
*/
t_rcode	action_negate(t_base *base,
		      t_token *n,
		      t_token *res)
{
  *res = *n;
  res->sign = res->sign == POSITIVE ? NEGATIVE : POSITIVE;
  free(n);
  return (OK);
}

t_rcode	extract_sub(char *c,
		    t_token *token,
		    t_base *base,
		    t_token *previous)
{
  if (!c)
    return (NULL_REFERENCE);
  if (previous &&
      (previous->type == RPARENTHESIS || previous->type == NUMBER))
    {
      token->type = OPERATOR;
      token->operator.action = &action_sub;
      token->operator.precedence = 5;
      token->size = 1;
      return (OK);
    }
  else
    {
      token->type = U_OPERATOR;
      token->operator.action = &action_negate;
      token->operator.precedence = 15;
      token->size = 1;
      return (OK);
    }
}
