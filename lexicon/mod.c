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
#include "operators.h"

t_rcode		action_mod(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_rcode	ret;
  t_token	*res_div;
  t_token	*res_mul;
  t_token	save_n1;

  if (n2->size == 1 && n2->string_value[0] == base->string[0])
    return (MODULO_BY_ZERO);
  if (n2->size == 1 && n2->string_value[0] == base->string[1])
    {
      res->string_value = &base->string[0];
      res->dynamic = FALSE;
      res->size = 1;
      return (OK);
    }
  if ((ret = bm_new_token(&res_div)) != OK ||
      (ret = bm_new_token(&res_mul)) != OK)
    return (ret);
  save_n1 = *n1;
  action_div(base, n1, n2, res_div);
  res_div->sign = POSITIVE;
  action_mul(base, n2, res_div, res_mul);
  action_sub_compute(base, &save_n1, res_mul, res);
  if (save_n1.sign == NEGATIVE)
    res->sign = NEGATIVE;
  else
    res->sign = POSITIVE;
  bm_free_token(res_mul);
  bm_free_token(n1);
  bm_free_token(n2);
  clean_number_str(base, res);
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
