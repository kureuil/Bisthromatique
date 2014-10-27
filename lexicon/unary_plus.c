/*
** unary_plus.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 17:14:49 2014 brendan rius
** Last update Mon Oct 27 17:23:57 2014 brendan rius
*/

#include "tokenizer.h"

int	action_unary_plus(int n)
{
  return (n);
}

unsigned int	extract_unary_plus(char *s, t_token *token)
{
  if (!s)
    return (0);
  if (s[0] == '+')
    {
      token->type = U_OPERATOR;
      token->value.operator.action = &action_unary_plus;
      token->value.operator.precedence = 15;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
