/*
** div.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:39 2014 brendan rius
** Last update Fri Nov  7 16:41:38 2014 Louis Person
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

t_rcode	action_div(t_base *base,
		   t_token *n1,
		   t_token *n2,
		   t_token *res)
{
  t_rcode	ret;

  if ((ret = malloc_token_dynamically(res, n1->size + n2->size)) != OK)
    return (ret);
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
