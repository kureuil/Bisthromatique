/*
** karatsuba_split.c for Bistromathique in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Nov  9 22:53:23 2014 Louis Person
** Last update Sun Nov  9 23:16:42 2014 Louis Person
*/

#include "tokens.h"
#include "boolean.h"
#include "bm_base.h"
#include "karatsuba_utils.h"
#include "bm_lexicon_utils.h"

void	make_delimiters_static(t_delimiters *delimiters)
{
  delimiters->a->dynamic = FALSE;
  delimiters->b->dynamic = FALSE;
  delimiters->c->dynamic = FALSE;
  delimiters->d->dynamic = FALSE;
}

void	split_token(t_token *n1,
		    t_token *n2,
		    t_delimiters *delimiters,
		    t_base *base)
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
      delimiters->c->string_value = &base->string[0];
      delimiters->c->sign = POSITIVE;
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
  make_delimiters_static(delimiters);
}

t_rcode		split_tokens(t_token *n1,
			     t_token *n2,
			     t_delimiters *delimiters,
			     t_base *base)
{
  t_token	*a;
  t_token	*b;
  t_token	*c;
  t_token	*d;
  t_rcode	ret;

  if ((ret = bm_new_token(&a)) != OK ||
      (ret = bm_new_token(&b)) != OK ||
      (ret = bm_new_token(&c)) != OK ||
      (ret = bm_new_token(&d)) != OK)
    return (ret);
  delimiters->a = a;
  delimiters->b = b;
  delimiters->c = c;
  delimiters->d = d;
  split_token(n1, n2, delimiters, base);
  clean_number_str(base, delimiters->a);
  clean_number_str(base, delimiters->b);
  clean_number_str(base, delimiters->c);
  clean_number_str(base, delimiters->d);
  return (OK);
}
