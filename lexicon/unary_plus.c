/*
** unary_plus.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 17:14:49 2014 brendan rius
** Last update Tue Oct 28 15:41:05 2014 brendan rius
*/

#include "tokens.h"
#include "bm_base.h"

t_rcode	action_unary_plus(t_base *base,
			  t_token *n,
			  t_token *res)
{
  base->size++;
  n->size++;
  res->size++;
  return (OK);
}

unsigned int	extract_unary_plus(char *s, t_token *token)
{
  if (!s)
    return (0);
  if (s[0] == '+')
    {
      token->type = U_OPERATOR;
      token->operator.action = &action_unary_plus;
      token->operator.precedence = 15;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
