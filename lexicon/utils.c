/*
** utils.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Thu Oct 30 18:57:36 2014 brendan rius
*/

#include "tokenizer.h"
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
