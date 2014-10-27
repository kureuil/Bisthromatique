/*
** parenthesis.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:29 2014 brendan rius
** Last update Mon Oct 27 15:56:29 2014 brendan rius
*/

#include "tokenizer.h"

unsigned int	extract_rparenthesis(char *c, t_token *token)
{
  if (!c || c[0] != ')')
    return (0);
  token->type = RPARENTHESIS;
  token->size = 1;
  return (token->size);
}

unsigned int	extract_lparenthesis(char *c, t_token *token)
{
  if (!c || c[0] != '(')
    return (0);
  token->type = LPARENTHESIS;
  token->size = 1;
  return (token->size);
}
