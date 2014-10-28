/*
** add.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Tue Oct 28 17:33:02 2014 brendan rius
*/

#include <stdlib.h>
#include "bm_errno.h"
#include "tokenizer.h"
#include "bm_base.h"
#include "my.h"

/*
** Can be optimized usin DP or BT
*/
int	get_nbr_from_base(t_base *base, char digit)
{
  int	i;

  i = 0;
  while (base->string[i] && base->string[i] != digit)
    ++i;
  return (i);
}

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

t_rcode	action_add(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res)
{
  int	shift;
  int	carry;
  int	cursor;
  int	tmp;
  int	nb1;
  int	nb2;

  reorder_tokens(&n1, &n2);
  shift = n1->size - n2->size;
  cursor = n1->size - 1;
  carry = 0;
  res->string_value = malloc(n1->size + 2);
  while (cursor >= 0 || carry)
    {
      nb1 = cursor >= 0 ? get_nbr_from_base(base, n1->string_value[cursor]) : 0;
      nb2 = cursor - shift >= 0 ? get_nbr_from_base(base, n2->string_value[cursor - shift]) : 0;
      tmp = nb1 + nb2 + carry;
      carry = 0;
      if (tmp >= base->size)
	{
	  carry = 1;
	  tmp %= base->size;
	}
      res->string_value[cursor] = base->string[tmp];
      --cursor;
    }
  res->string_value[n1->size + 1] = '\0';
  return (OK);
}

unsigned int	extract_add(char *c, t_token *token, t_token *previous)
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
