/*
** my_go_to_next_string.c for my_go_to_next_string in /home/rius_b/rendu/Piscine_C_J08/ex_04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct 10 11:04:00 2014 brendan rius
** Last update Fri Oct 10 18:12:05 2014 brendan rius
*/

#include <stdlib.h>

char	*go_to_next_string(char *str, short fct(char))
{
  while (*str)
    {
      if (fct(*str))
	return (str);
      ++str;
    }
  return (NULL);
}
