/*
** mod.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:54 2014 brendan rius
** Last update Tue Oct 28 15:31:19 2014 brendan rius
*/

#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"

t_rcode	action_mod(t_base *base,
		   t_token *n1,
		   t_token *n2,
		   t_token *res)
{
  clean_number_str(base, n2);
  if (n2->size == 1 && get_value_at_index(base, n2->string_value, 0) == 0)
    return (MODULO_BY_ZERO);
  return (OK);
}

t_rcode	extract_mod(char *c, t_token *token)
{
  if (!c)
    return (NULL_REFERENCE);
  token->type = OPERATOR;
  token->operator.action = &action_mod;
  token->operator.precedence = 10;
  token->size = 1;
  return (OK);
}
