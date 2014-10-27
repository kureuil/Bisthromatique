/*
** negate.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:14 2014 brendan rius
** Last update Mon Oct 27 15:56:14 2014 brendan rius
*/

#include "tokenizer.h"

int	action_negate(int n)
{
  return (-n);
}

unsigned int	extract_negate(char *c, t_token *token)
{
  if (!c)
    return (0);
  if (c[0] == '-')
    {
      token->type = U_OPERATOR;
      token->value.operator.action = &action_negate;
      token->value.operator.precedence = 15;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
