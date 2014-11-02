/*
** utils.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Sat Nov  1 21:22:55 2014 Louis Person
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

int	my_strcmp_base(struct s_token n1, struct s_token n2, t_base base)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  while (get_value_at_index(*(s1 + i)) == get_value_at_index(*(s2 + i)))
    {
      if (*(s1 + i) == '\0')
	return (0);
      ++i;
    }
  if (get_value_at_index(*(s1 + i)) < get_value_at_index(*(s2 + i)))
    return (-1);
  else
    return (1);
}
