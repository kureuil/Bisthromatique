/*
** sub.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:36 2014 brendan rius
** Last update Mon Oct 27 15:56:37 2014 brendan rius
*/

#include "tokenizer.h"

int	action_sub(int n1, int n2)
{
  return (n1 - n2);
}

unsigned int	extract_sub(char *c, t_token *token, t_token *previous)
{
  if (!c)
    return (0);
  if (c[0] == '-' &&
      (previous &&
       (previous->type == RPARENTHESIS || previous->type == NUMBER)))
    {
      token->type = OPERATOR;
      token->value.operator.action = &action_sub;
      token->size = 1;
      token->value.operator.precedence = 5;
      return (token->size);
    }
  return (0);
}
