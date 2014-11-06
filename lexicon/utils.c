/*
** utils.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Tue Nov  4 12:22:26 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "bm_base.h"
#include "boolean.h"

void			reorder_tokens(t_token **n1,
				       t_token **n2)
{
  struct s_token	*tmp;

  tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
}

int	get_value_at_index(t_base *base, char *number, int index)
{
  if (index >= 0)
    return (base->array[(unsigned char) number[index]]);
  else
    return (0);
}

t_rcode	clean_number_str(t_base *base, t_token *token)
{
  while (get_value_at_index(base, token->string_value, 0) <= 0 &&
	 token->size > 1)
    {
      token->size--;
      token->string_value++;
    }
  return (OK);
}

int	my_strcmp_base(struct s_token *n1, struct s_token *n2, t_base *base)
{
  int	i;

  i = 0;
  if (!n1->string_value || !n2->string_value)
    return (0);
  if (n1->size != n2->size)
    return (n1->size - n2->size);
  while (n1->string_value[i] == n2->string_value[i])
    {
      if (i == n1->size - 1)
	return (0);
      ++i;
    }
  return (n1->string_value[i] - n2->string_value[i]);
}

t_rcode	malloc_token_dynamically(t_token *token, int size)
{
  if ((token->string_value = malloc(size)) == NULL)
    return (COULD_NOT_MALLOC);
  token->dynamic = TRUE;
  token->real_address = token->string_value;
  return (OK);
}
