/*
** mul.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:03 2014 brendan rius
** Last update Tue Oct 28 15:27:39 2014 brendan rius
*/

#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"

t_rcode	action_mul(t_base *base,
		   t_token *n1,
		   t_token *n2,
		   t_token *res)
{
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
