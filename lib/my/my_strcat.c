/*
** my_strcat.c for my_strcat in /home/rius_b/rendu/Piscine_C_J07/ex_01
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct  7 09:08:13 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

char	*my_strcat(char *dest, char *src)
{
  char	*d;

  d = dest;
  if (!dest || !src)
    return (dest);
  while (*dest++);
  dest -= 1;
  while (*src)
    *dest++ = *src++;
  *dest = '\0';
  return (d);
}
