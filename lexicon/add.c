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
#include "tokenizer.h"
#include "bm_base.h"
#include "my.h"

void			reorder_tokens(struct s_token **n1,
				       struct s_token **n2)
{
  struct s_token	*tmp;

  if ((*n2)->size <= (*n1)->size)
    return;
  tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
}

int	get_value_at_index(struct s_base *base, char *number, int index)
{
  if (index >= 0)
    return (base->array[(unsigned char) number[index]]);
  else
    return (0);
}

t_rcode	clean_number_str(t_base *base, t_token token)
{
  while (get_value_at_index(base, token->string_value, 0) == -1)
    {
      token->size--;
      token->string_value++;
    }
  return (OK);
}

t_rcode	action_add(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res)
{
  int	carry;
  int	cursor;
  int	shift_n1_n2;
  int	shift_res_n1;
  int	tmp;

  reorder_tokens(&n1, &n2);
  res->size = n1->size + 1;
  if (!(res->string_value = malloc(res->size)))
    return (COULD_NOT_MALLOC);
  carry = 0;
  cursor = n1->size - 1;
  shift_n1_n2 = n1->size - n2->size;
  shift_res_n1 = res->size - n1->size;
  while (cursor >= 0 || carry)
    {
      tmp = (get_value_at_index(base, n1->string_value, cursor) +
	     get_value_at_index(base, n2->string_value, cursor - shift_n1_n2) +
	     carry);
      if (tmp >= base->size)
	carry = 1;
      else
	carry = 0;
      res->string_value[cursor + shift_res_n1] = base->string[tmp % base->size];
      --cursor;
    }
  clean_number_str(base, res);
  bm_free_token(n1);
  bm_free_token(n2);
  return (OK);
}

unsigned int	extract_add(char *c,
			    t_token *token,
			    t_base *base,
			    t_token *previous)
{
  base->size = base->size;
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
