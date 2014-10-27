/*
** my_show_wordtab.c for my_show_wordtab in /home/rius_b/rendu/Piscine_C_J08/ex_05
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  9 21:24:38 2014 brendan rius
** Last update Fri Oct 10 21:55:23 2014 brendan rius
*/

#include <stdlib.h>

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
  return (0);
}
