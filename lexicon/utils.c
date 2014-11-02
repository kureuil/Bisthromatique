/*
** utils.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Sun Nov  2 15:42:40 2014 Louis Person
*/

#include "tokens.h"
#include "bm_base.h"

void			reorder_tokens(t_token **n1,
				       t_token **n2)
{
  struct s_token	*tmp;

  if ((*n2)->size <= (*n1)->size)
    return;
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
  while (get_value_at_index(base, token->string_value, 0) == -1)
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
  while (i < n1->size && i < n2->size && get_value_at_index(base, n1->string_value, i) == get_value_at_index(base, n2->string_value, i))
    {
      if (i == n1->size && i == n2->size)
	return (0);
      ++i;
    }
  if (get_value_at_index(base, n1->string_value, i) < get_value_at_index(base, n2->string_value, i))
    return (-1);
  else
    return (1);
}

t_rcode	get_complementary_number(struct s_token *nbr,
				 struct s_base *base,
				 struct s_token *res)
{
  int	cursor;

  if (!(res->string_value = malloc(nbr->size + 1)))
    return (COULD_NOT_MALLOC);
  res->string_value[nbr->size] = '\0';
  res->size = nbr->size;
  cursor = nbr->size - 1;
  while (cursor >= 0)
    {
      res->string_value[cursor] = (base->size - 1) - get_value_at_index(base, nbr->string_value, cursor);
      cursor--;
    }
}
