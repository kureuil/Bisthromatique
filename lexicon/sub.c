/*
** sub.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:36 2014 brendan rius
** Last update Sun Nov  2 15:42:55 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "bm_errno.h"
#include "bm_lexicon_utils.h"
#include "operators.h"
#include "my.h"

void		reorder_tokens_sub(t_token *n1, t_token *n2, t_base *base)
{
  reorder_tokens(&n1, &n2);
  if (n1->size != n2->size)
    return;
  if (my_strcmp_base(n1, n2, base) > 0)
    reorder_tokens(&n1, &n2);
}

#include <stdio.h>

t_rcode		action_sub(t_base *base,
			   t_token *n1,
			   t_token *n2,
			   t_token *res)
{
  t_token	*tmp;
  t_rcode	ret;

  if (n2->sign == NEGATIVE && n1->sign == POSITIVE)
    return ((ret = action_add(base, n1, n2, res)) != OK ? ret : OK);
  if (n1->sign == NEGATIVE && n2->sign == POSITIVE)
    reorder_tokens(&n1, &n2);
  res->size = n1->size > n2->size ? n1->size : n2->size;
  if (!(res->string_value = malloc(res->size)))
    return (COULD_NOT_MALLOC);
  if ((ret = bm_new_token(&tmp)) != OK)
    return (ret);
  get_complementary_number(n2, base, tmp);
  action_add(base, n2, tmp, );
  clean_number_str(base, res);
  /*bm_free_token(n1);
    bm_free_token(n2);*/
  return (OK);
}

unsigned int	extract_sub(char *c,
			    t_token *token,
			    t_base *base,
			    t_token *previous)
{
  base->size = base->size;
  if (!c)
    return (0);
  if (c[0] == '-' &&
      (previous &&
       (previous->type == RPARENTHESIS || previous->type == NUMBER)))
    {
      token->type = OPERATOR;
      token->operator.action = &action_sub;
      token->operator.precedence = 5;
      token->size = 1;
      return (token->size);
    }
  return (0);
}
