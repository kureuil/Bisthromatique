/*
** my_strncpy.c for my_strncpy.c in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 08:55:08 2014 brendan rius
** Last update Thu Oct  9 09:39:49 2014 brendan rius
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && *(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  if (i < n)
    *(dest + i) = '\0';
  return (dest);
}
