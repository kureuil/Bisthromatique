/*
** my_strlen.c for my_strlen.c in /home/rius_b/rendu/Piscine_C_J04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  2 08:49:08 2014 brendan rius
** Last update Thu Oct  9 09:39:50 2014 brendan rius
*/

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}
