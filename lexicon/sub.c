/*
** sub.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:36 2014 brendan rius
** Last update Tue Oct 28 15:35:45 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "bm_base.h"
#include "bm_errno.h"

t_rcode		action_sub(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  base->size++;
  n1->size++;
  n2->size++;
  res->size++;
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
