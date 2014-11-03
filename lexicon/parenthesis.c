/*
** parenthesis.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:29 2014 brendan rius
** Last update Mon Oct 27 15:56:29 2014 brendan rius
*/

#include "tokens.h"
#include "bm_errno.h"

t_rcode	extract_rparenthesis(char *c, t_token *token)
{
  if (!c)
    return (NULL_REFERENCE);
  token->type = RPARENTHESIS;
  token->size = 1;
  return (OK);
}

t_rcode	extract_lparenthesis(char *c, t_token *token)
{
  if (!c)
    return (NULL_REFERENCE);
  token->type = LPARENTHESIS;
  token->size = 1;
  return (OK);
}
