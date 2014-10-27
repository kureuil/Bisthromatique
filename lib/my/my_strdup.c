/*
** my_strdup.c for my_strdup in /home/rius_b/rendu/Piscine_C_J08
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Oct  8 08:48:50 2014 brendan rius
** Last update Thu Oct  9 23:31:40 2014 brendan rius
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*new_src;
  int	i;

  i = 0;
  new_src = malloc(my_strlen(src) + 1);
  if (new_src == NULL)
    return (NULL);
  while (*src)
    *(new_src + i++) = *src++;
  *(new_src + i) = '\0';
  return (new_src);
}
