/*
** my_strlowcase.c for my_strlowcase in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 11:42:34 2014 brendan rius
** Last update Thu Oct  9 09:39:50 2014 brendan rius
*/

char	*my_strlowcase(char *str)
{
  int	i;
  int	gap;

  if (!str)
    return (str);
  i = 0;
  gap = 'a' - 'A';
  while (*(str + i) != '\0')
    {
      if (*(str + i) <= 'Z'  && *(str + i) >= 'A')
	*(str + i) += gap;
      ++i;
    }
  return (str);
}
