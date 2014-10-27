/*
** my_strncat.c for my_strncat.c in /home/rius_b/rendu/Piscine_C_J07/ex_01
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct  7 09:26:55 2014 brendan rius
** Last update Thu Oct  9 09:39:50 2014 brendan rius
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  char	*d;

  d = dest;
  if (!dest || !src)
    return (dest);
  while (*dest++);
  dest -= 1;
  while (*src && nb--)
    *dest++ = *src++;
  *dest = '\0';
  return (d);
}
