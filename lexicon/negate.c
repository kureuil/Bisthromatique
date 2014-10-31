/*
** negate.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:14 2014 brendan rius
** Last update Wed Oct 29 15:49:22 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "bm_base.h"

/*
** We could speed this up by avoiding copying n into res
*/
t_rcode	action_negate(t_base *base,
		      t_token *n,
		      t_token *res)
{
  *res = *n;
  res->sign = res->sign == POSITIVE ? NEGATIVE : POSITIVE;
  free(n);
  return (OK);
}

unsigned int	extract_negate(char *c, t_token *token)
{
  if (!c)
    return (0);
  if (c[0] == '-')
    {
      token->type = U_OPERATOR;
      token->operator.action = &action_negate;
      token->operator.precedence = 15;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
