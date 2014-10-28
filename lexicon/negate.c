/*
** negate.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:14 2014 brendan rius
** Last update Tue Oct 28 15:37:18 2014 brendan rius
*/

#include "tokenizer.h"
#include "bm_base.h"

t_rcode	action_negate(t_base *base,
		      t_token *n,
		      t_token *res)
{
  base->size++;
  n->size++;
  res->size++;
  return (OK);
}

unsigned int	extract_negate(char *c, t_token *token)
{
  if (!c)
    return (0);
  if (c[0] == '-')
    {
      token->type = U_OPERATOR;
      token->operator.action = &action_negate;
      token->operator.precedence = 15;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
