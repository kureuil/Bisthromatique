/*
** div.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:39 2014 brendan rius
** Last update Mon Oct 27 15:55:39 2014 brendan rius
*/

#include "tokenizer.h"

int	action_div(int n1, int n2)
{
  return (n1 / n2);
}

unsigned int	extract_div(char *c, t_token *token)
{
  if (!c || c[0] != '/')
    return (0);
  token->type = OPERATOR;
  token->value.operator.action = &action_div;
  token->value.operator.precedence = 10;
  token->size = 1;
  return (token->size);
}
