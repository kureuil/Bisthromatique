/*
** sub.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:36 2014 brendan rius
** Last update Sat Nov  1 16:03:23 2014 Louis Person
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"

t_rcode		action_sub(t_base *base,
			   t_token *n2,
			   t_token *n1,
			   t_token *res)
{
  int	carry;
  int	cursor;
  int	shift_n1_n2;
  int	tmp;

  res->size = n1->size > n2->size ? n1->size : n2->size;
  if (!(res->string_value = malloc(res->size)))
    return (COULD_NOT_MALLOC);
  carry = 0;
  cursor = n1->size > n2->size ? n1->size - 1 : n2->size - 1;
  shift_n1_n2 = n1->size - n2->size;
  while (cursor >= 0 || carry)
    {
      tmp = (get_value_at_index(base, n1->string_value, cursor) -
	     (get_value_at_index(base, n2->string_value, cursor - shift_n1_n2) +
	      carry));
      if (tmp < 0)
	{
	  if (cursor > 0)
	    {
	      carry = 1;
	      tmp = base->size + tmp;
	      res->string_value[cursor] = base->string[tmp];
	    }
	  else
	    {
	      carry = 0;
	      res->sign = NEGATIVE;
	      res->string_value[cursor] = base->string[tmp < 0 ? -tmp : tmp];
	    }
	}
      else
	{
	  carry = 0;
	  res->string_value[cursor] = base->string[tmp];
	}
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
