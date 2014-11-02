/*
** sub.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:36 2014 brendan rius
** Last update Sun Nov  2 13:36:03 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "operators.h"
#include "my.h"

void		reorder_tokens_sub(t_token n1, t_token n2, t_base base)
{
  reorder_tokens(&n2, &n1);
  if (n1->size != n2->size)
    return;
  if (my_strcmp_base(n1, n2, base))
    {
      
    }
}

t_rcode		action_sub(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  int		carry;
  int		cursor;
  int		shift_n1_n2;
  int		tmp;
  t_rcode	ret;

  reorder_tokens_sub(n1, n2, base);
  if (n2->sign == NEGATIVE && n1->sign == POSITIVE)
    return ((ret = action_add(base, n1, n2, res)) != OK ? ret : OK);
  if (n1->sign == NEGATIVE && n2->sign == POSITIVE)
    reorder_tokens(&n1, &n2);
  res->size = n1->size > n2->size ? n1->size : n2->size;
  if (!(res->string_value = malloc(res->size)))
    return (COULD_NOT_MALLOC);
  carry = 0;
  cursor = n1->size > n2->size ? n1->size - 1 : n2->size - 1;
  shift_n1_n2 = n1->size - n2->size;
  printf("n1->size: %d | n2->size: %d | shift: %d\n", n1->size, n2->size, shift_n1_n2);
  while (cursor >= 0 || carry)
    {
      tmp = (get_value_at_index(base, n1->string_value, cursor) -
	     get_value_at_index(base, n2->string_value, cursor - shift_n1_n2) -
	     carry);
      carry = 0;
      if (tmp < 0)
	{
	  tmp = base->size + tmp;
	  carry = 1;
	  if (cursor < 0)
	    res->sign = NEGATIVE;
	}
      printf("tmp: %d | n1: %d | n2: %d | carry: %d | cursor: %d\n", tmp, get_value_at_index(base, n1->string_value, cursor), get_value_at_index(base, n2->string_value, cursor -shift_n1_n2), carry, cursor);
      res->string_value[cursor] = base->string[tmp];
      --cursor;
    }
  clean_number_str(base, res);
  bm_free_token(n1);
  bm_free_token(n2);
  return (OK);
}

unsigned int	extract_sub(char *c,
			    t_token *token,
			    t_base *base,
			    t_token *previous)
{
  base->size = base->size;
  if (!c)
    return (0);
  if (c[0] == '-' &&
      (previous &&
       (previous->type == RPARENTHESIS || previous->type == NUMBER)))
    {
      token->type = OPERATOR;
      token->operator.action = &action_sub;
      token->operator.precedence = 5;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
