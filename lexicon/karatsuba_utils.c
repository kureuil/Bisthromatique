/*
** karatsuba_utils.c for Bistromathique in /home/brendan/rendu/Bistromathique/lexicon
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Nov  6 15:06:35 2014 Brendan Rius
** Last update Thu Nov  6 15:06:35 2014 Brendan Rius
*/

#include <stdlib.h>
#include "bm_errno.h"
#include "bm_tokens.h"
#include "boolean.h"

t_rcode	pow_base(t_base *base, int multiplier, t_token *res)
{
  int	i;

  res->dynamic = TRUE;
  res->size = multiplier + 1
  if ((res->string_value = res->real_address = malloc(res->size)) == NULL)
    return (COULD_NOT_MALLOC);
  res->string_value[0] = base->string[1];
  i = 1;
  while (i < res->size)
    {
      res->string_value[i] = base->string[0];
      ++i;
    }
  return (OK);
}
