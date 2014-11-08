/*
** div.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:39 2014 brendan rius
** Last update Sat Nov  8 23:42:10 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "my.h"

t_rcode		action_div_by_two(t_base *base, t_token *n1, t_token *res)
{
  int	cursor;
  int	tmp;
  int	rest;

  cursor = 0;
  if (malloc_token_dynamically(res, n1->size) != OK)
    return (COULD_NOT_MALLOC);
  my_putstr("\tcccc\n");
  while (cursor < n1->size)
    {
      tmp = get_value_at_index(base, n1->string_value, cursor) / 2;
      rest = get_value_at_index(base, n1->string_value, cursor) - 2 * tmp;
      if (cursor > 0 && n1->string_value[cursor - 1] == base->string[1])
	{
	  res->string_value[cursor] = base->string[tmp + base->size / 2];
	  n1->string_value[cursor - 1] = base->string[0];
	}
      else
	res->string_value[cursor] = base->string[tmp];
      n1->string_value[cursor] = base->string[rest];
      cursor++;
    }
  clean_number_str(base, n1);
  clean_number_str(base, res);
  return (OK);
}

t_rcode		action_div_compute(t_base *base,
				   t_token *n1,
				   t_token *n2,
				   t_token *res)
{
  t_token	*min;
  t_token	*tmp;
  t_token	*max;
  t_token	*cursor;
  t_rcode	ret;

  if ((ret = bm_new_token(&min)) != OK ||
      (ret = bm_new_token(&tmp)) != OK ||
      (ret = bm_new_token(&max)) != OK ||
      (ret = bm_new_token(&cursor)) != OK)
    return (ret);
  if ((malloc_token_dynamically(min, 1)) != OK ||
      (malloc_token_dynamically(max, n1->size)) != OK ||
      (malloc_token_dynamically(tmp, n1->size)) != OK)
    return (COULD_NOT_MALLOC);
  min->string_value[0] = base->string[0];
  my_strncpy(max->string_value, n1->string_value, n1->size);
  while (my_strcmp_base(tmp->string_value, min->string_value, base))
    {
      bm_print_token(min);
      bm_print_token(max);
      action_add_compute(base, min, max, tmp);
      clean_number_str(base, tmp);
      if ((malloc_token_dynamically(cursor, max->size)) != OK)
	return (COULD_NOT_MALLOC);
      bm_print_token(tmp);
      my_putstr("\taaaa\n");
      if (action_div_by_two(base, tmp, cursor) != OK)
	return (COULD_NOT_MALLOC);
      my_putstr("\tbbbb\n");
      bm_print_token(cursor);
      if ((malloc_token_dynamically(tmp, cursor->size + n2->size)) != OK)
	return (COULD_NOT_MALLOC);
      action_mul(base, cursor, n2, tmp);
      if (my_strcmp(tmp->string_value, n1->string_value) > 0)
	max = tmp;
      else
	min = tmp;
    }
  *res = *min;
  bm_free_token(min);
  bm_free_token(max);
  bm_free_token(tmp);
  bm_free_token(cursor);
  return (OK);
}

t_rcode		action_div(t_base *base,
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
