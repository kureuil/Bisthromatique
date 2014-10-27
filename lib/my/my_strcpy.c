/*
** my_strcpy.c for my_strcpy in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 08:49:52 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

char	*my_strcpy(char *dest, char *src)
{
  if (!dest || !src)
    return (0);
  while (*src != '\0')
    {
      *dest = *src;
      src += 1;
      dest += 1;
    }
  *dest = '\0';
  return (dest);
}
