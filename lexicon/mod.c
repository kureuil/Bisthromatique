/*
** mod.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:54 2014 brendan rius
** Last update Tue Oct 28 15:31:19 2014 brendan rius
*/

#include "tokenizer.h"
#include "bm_base.h"

t_rcode	action_mod(t_base *base,
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

unsigned int	extract_mod(char *c, t_token *token)
{
  if (!c || c[0] != '%')
    return (0);
  token->type = OPERATOR;
  token->operator.action = &action_mod;
  token->operator.precedence = 10;
  token->size = 1;
  return (token->size);
}
