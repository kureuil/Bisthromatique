/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/rius_b/rendu/Piscine_C_J08/ex_03
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Oct  8 11:11:58 2014 brendan rius
** Last update Tue Oct 21 11:10:45 2014 brendan rius
*/

#include <stdlib.h>
#include "my.h"

int	my_fill_array(char **array, char *str)
{
  int	i;
  char	*str_cpy;
  short	(*fct)(char);

  fct = my_char_isalphanum;
  i = 0;
  str_cpy = str;
  while ((str = go_to_next_string(str_cpy, fct)) != NULL)
    {
      str_cpy = str;
      while (my_char_isalphanum(*str_cpy))
	++str_cpy;
      if (str_cpy == '\0')
	return (0);
      *str_cpy = '\0';
      array[i] = str;
      ++i;
      ++str_cpy;
    }
  return (1);
}

char	**my_str_to_wordtab(char *str)
{
  char	**array;
  int	words;

  words = my_count_strings(str, my_char_isalphanum);
  array = malloc(sizeof(char*) * words + 1);
  if (array == NULL)
    return (NULL);
  if (!my_fill_array(array, str))
    {
      free(array);
      return (NULL);
    }
  array[words] = (char*) 0;
  return (array);
}
