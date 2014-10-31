/*
** bm_base.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct 30 13:11:05 2014 brendan rius
** Last update Thu Oct 30 18:00:39 2014 brendan rius
*/

#include "bm_base.h"
#include "my.h"

t_rcode	new_base(char *string, t_base *base)
{
  int	i;

  if (!string)
    return (NULL_REFERENCE);
  base->size = my_strlen(string);
  if (base->size < 2)
    return (WRONG_BASE_LEN);
  i = 0;
  while (i < MAX_BASE_SIZE)
    {
      base->array[i] = -1;
      ++i;
    }
  i = 0;
  while (i < base->size)
    {
      if (base->array[(unsigned char) string[i]] != -1)
	return (DUPLICATE_VALUE_IN_BASE);
      base->array[(unsigned char) string[i]] = i;
      ++i;
    }
  base->string = string;
  return (OK);
}
