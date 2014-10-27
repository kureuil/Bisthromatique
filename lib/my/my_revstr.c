/*
** my_revstr.c for my_revstr in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 08:58:09 2014 brendan rius
** Last update Thu Oct  9 09:39:55 2014 brendan rius
*/

char	*my_revstr(char *str)
{
  int	len;
  int	i;
  char	tmp;

  if (!str)
    return (0);
  len = my_strlen(str);
  i = 0;
  while (i <= len / 2 - 1)
    {
      tmp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = tmp;
      ++i;
    }
  return (str);
}
