/*
** add.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Thu Oct 30 18:57:36 2014 brendan rius
*/

#include <stdlib.h>
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "tokens.h"
#include "bm_base.h"
#include "my.h"

t_rcode	action_add(t_base *base,
		   t_token *n1,
		   t_token *n2,
		   t_token *res)
{
  int	carry;
  int	cursor;
  int	shift_n1_n2;
  int	tmp;

  reorder_tokens(&n1, &n2);
  res->size = n1->size + 1;
  if (!(res->string_value = malloc(res->size)))
    return (COULD_NOT_MALLOC);
  res->real_address = res->string_value;
  carry = 0;
  cursor = n1->size - 1;
  shift_n1_n2 = n1->size - n2->size;
  while (cursor >= 0 || carry)
    {
      tmp = (get_value_at_index(base, n1->string_value, cursor) +
	     get_value_at_index(base, n2->string_value, cursor - shift_n1_n2) +
	     carry);
      carry = tmp >= base->size ? 1 : 0;
      res->string_value[cursor + 1] = base->string[tmp % base->size];
      --cursor;
    }
  clean_number_str(base, res);
  return (OK);
}

unsigned int	extract_add(char *c,
			    t_token *token,
			    t_base *base,
			    t_token *previous)
{
   if (!c)
    return (0);
  if (c[0] == '+' &&
      (previous &&
       (previous->type == RPARENTHESIS || previous->type == NUMBER)))
    {
      token->type = OPERATOR;
      token->operator.action = &action_add;
      token->operator.precedence = 5;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
