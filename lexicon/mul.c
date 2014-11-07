/*
** mul.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:03 2014 brendan rius
** Last update Fri Nov  7 16:14:58 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "my.h"
#include "boolean.h"

t_rcode		action_mul(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  /*t_rcode	ret;

  if (n1->size > n2->size)
    reorder_tokens;
  if (n1->sign == NEGATIVE ^ n2->sign == NEGATIVE)
    res->sign = NEGATIVE;
  if ((ret = malloc_token_dynamically(res, n1->size + n2->size)) != OK)
  return (ret);*/
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
