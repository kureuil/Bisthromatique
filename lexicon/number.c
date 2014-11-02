/*
** number.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:22 2014 brendan rius
** Last update Mon Oct 27 15:56:22 2014 brendan rius
*/

#include "tokens.h"
#include "bm_base.h"

unsigned int	extract_number(char *s,
			       t_token *token,
			       t_base *base)
{
  int		size;

  if (!s || !*s)
    return (0);
  size = 0;
  while (*s && base->array[(unsigned char) *s] != -1)
    {
      token->type = NUMBER;
      ++size;
      ++s;
    }
  if (size != 0)
    token->size = size;
  return (size);
}
