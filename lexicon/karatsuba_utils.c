/*
** karatsuba_utils.c for Bistromathique in /home/brendan/rendu/Bistromathique/lexicon
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Nov  6 15:06:35 2014 Brendan Rius
** Last update Thu Nov  6 15:17:34 2014 Louis Person
*/

#include <stdlib.h>
#include "bm_errno.h"
#include "tokens.h"
#include "boolean.h"
#include "bm_lexicon_utils.h"
#include "bm_base.h"
#include "karatsuba_utils.h"

t_rcode	split_token(t_token *n1,
		    t_token *n2,
		    t_delimiters *delimiters)
{
  int	size;

  if (n2->size > n1->size)
    reorder_tokens(&n1, &n2);
  size = (n1->size + 1) / 2;
  delimiters->a->string_value = n1->string_value;
  delimiters->a->size = size;
  delimiters->b->string_value = n1->string_value + size;
  delimiters->b->size = n1->size - size;
  if (size >= n2->size / 2)
    {
      delimiters->c->string_value = "0";
      delimiters->c->size = 1;
      delimiters->d->string_value = n2->string_value;
      delimiters->d->size = n2->size;
    }
  else
    {
      delimiters->c->string_value = n2->string_value;
      delimiters->c->size = size;
      delimiters->d->string_value = n2->string_value + size;
      delimiters->d->size = n2->size - size;
    }

  delimiters->a->dynamic = FALSE;
  delimiters->b->dynamic = FALSE;
  delimiters->c->dynamic = FALSE;
  delimiters->d->dynamic = FALSE;
  return (OK);
}

t_rcode		pad(t_token *t, t_base *base, int nb, t_token *res)
{
  t_rcode	ret;
  int		i;

  if ((ret = malloc_token_dynamically(res, t->size + nb)) != OK)
    return (ret);
  res->type = NUMBER;
  i = 0;
  while (i < t->size + nb)
    {
      if (i < t->size)
	res->string_value[i] = t->string_value[i];
      else
	res->string_value[i] = base->string[0];
      ++i;
    }
  return (OK);
}
