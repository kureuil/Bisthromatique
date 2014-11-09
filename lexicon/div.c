/*
** div.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:39 2014 brendan rius
** Last update Sun Nov  9 21:24:18 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "my.h"

t_rcode		action_div_prepare(t_base *base,
				   t_token *n1,
				   t_token *n2,
				   t_token *res)
{
  if ((n1->sign == NEGATIVE) ^ (n2->sign == NEGATIVE))
    res->sign = NEGATIVE;
  if (n2->size == 1)
    {
      if (n2->string_value[0] == base->string[0])
	{
	  bm_free_token(n1);
	  bm_free_token(n2);
	  return (DIVISION_BY_ZERO);
	}
      else if (n2->string_value[0] == base->string[1])
	{
	  res->string_value = n1->string_value;
	  res->size = n1->size;
	  if (!((n1->sign == NEGATIVE) ^ (n2->sign == NEGATIVE)))
	    res->sign = POSITIVE;
	  bm_free_token(n2);
	  return (DIVISION_BY_ITSELF);
	}
    }
  n1->sign = n2->sign = POSITIVE;
  if ((malloc_token_dynamically(res, n1->size)) != OK)
    return (COULD_NOT_MALLOC);
  my_memset(res->string_value, base->string[0], n1->size);
  return (OK);
}

void	action_div_get_tmp_tokens(t_base *base, t_token *res_tmp, t_token *one)
{  
  res_tmp->string_value = &base->string[0];
  res_tmp->dynamic = FALSE;
  res_tmp->size = 1;
  res_tmp->sign = POSITIVE;
  one->string_value = &base->string[1];
  one->size = 1;
  one->sign = POSITIVE;
  one->dynamic = FALSE;
}

t_rcode		action_div_compute(t_base *base,
				   t_token *n1,
				   t_token *n2,
				   t_token *res)
{
  t_token	res_tmp;
  t_token	one;
  t_token	*previous;

  action_div_get_tmp_tokens(base, &res_tmp, &one);
  if ((bm_new_token(&previous)) != OK)
    return (COULD_NOT_MALLOC);
  while (n1->sign == POSITIVE && n1->string_value[0] != base->string[0])
    {
      action_sub_compute(base, n1, n2, previous);
      clean_number_str(base, previous);
      *n1 = *previous;
      action_add_compute(base, &res_tmp, &one, res);
      res_tmp = *res;
    }
  if (n1->sign == NEGATIVE)
    {
      action_sub_compute(base, &res_tmp, &one, res);
      clean_number_str(base, res);
      return (OK);
    }
  res->string_value = res_tmp.string_value;
  res->size = res_tmp.size;
  res->sign = res_tmp.sign;
  return (OK);
}

t_rcode		action_div(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_rcode	ret;
  t_token	res_tmp;
  t_token	one;

  if ((ret = action_div_prepare(base, n1, n2, res)) != OK)
    return (ret == DIVISION_BY_ITSELF ? OK : ret);
  action_div_get_tmp_tokens(base, &res_tmp, &one);
  if (n2->size > n1->size)
    {
      *res = res_tmp;
      return (OK);
    }
  n1->dynamic = FALSE;
  action_div_compute(base, n1, n2, res);
  if (res->size == 1 && res->string_value[0] == base->string[0])
    res->sign = POSITIVE;
  return (OK);
}

t_rcode	extract_div(char *c, t_token *token)
{
  if (!c)
    return (NULL_REFERENCE);
  token->type = OPERATOR;
  token->operator.action = &action_div;
  token->operator.precedence = 10;
  token->size = 1;
  return (OK);
}
