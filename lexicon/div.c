/*
** div.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:39 2014 brendan rius
** Last update Fri Nov  7 22:45:26 2014 Louis Person
*/

#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "my.h"

t_rcode action_div_by_two(t_base *base, t_token *n1, t_token *res)
{
  int		cursor;
  int		tmp;
  t_rcode	ret;

  cursor = n1->size - 1;
  if ((ret = malloc_token_dynamically(res, n1->size)) != OK)
    return (ret);
  while (cursor >= 0)
    {
      if (n1->string_value[cursor] == base->string[0] &&
	  cursor - 1 >= 0 &&
	  n1->string_value[cursor - 1] != base->string[0])
	  res->string_value[cursor] = base->string[base->size / 2] +
	    get_value_at_index(base, n1->string_value, cursor) / 2;
      else
	{
	  tmp = get_value_at_index(base, n1->string_value, cursor);
	  res->string_value[cursor] = base->string[tmp / 2];
	}
      cursor--;
    }
  bm_free_token(n1);
  clean_number_str(base, res);
  return (OK);
}

t_rcode	action_div_compute(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_token	*min;
  t_token	*tmp;
  t_token	*max;
  t_token	*cursor;

  if ((malloc_token_dynamically(min, 1)) != OK ||
      (malloc_token_dynamically(max, n1->size)) != OK)
    return (COULD_NOT_MALLOC);
  while (my_strcmp(tmp->string_value, min->string_value))
    {
      action_add_compute(base, min, max, tmp);
      action_div_by_two(base, tmp, cursor);
      action_mul(base, cursor, n2, tmp);
      if (my_strcmp(tmp->string_value, n1->string_value) > 0)
	max = tmp;
      else
	min = tmp;
    }
  bm_free_token(min);
  bm_free_token(max);
  bm_free_token(tmp);
  bm_free_token(cursor);
  return (OK);
}

t_rcode	action_div(t_base *base,
		   t_token *n1,
		   t_token *n2,
		   t_token *res)
{
  t_rcode	ret;

  if ((ret = malloc_token_dynamically(res, n1->size + n2->size)) != OK)
    return (ret);
  action_div_compute(base, n1, n2, res);
  bm_free_token(n1);
  bm_free_token(n2);
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
