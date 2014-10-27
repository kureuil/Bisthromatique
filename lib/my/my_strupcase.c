/*
** my_strupcase.c for my_strupcase in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 11:29:42 2014 brendan rius
** Last update Thu Oct  9 09:39:49 2014 brendan rius
*/

char	*my_strupcase(char *str)
{
  int	i;
  int	gap;

  if (!str)
    return (str);
  i = 0;
  gap = 'a' - 'A';
  while (*(str + i) != '\0')
    {
      if (*(str + i) <= 'z'  && *(str + i) >= 'a')
	*(str + i) -= gap;
      ++i;
    }
  return (str);
}
