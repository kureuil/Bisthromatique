/*
** my_str_isnum.c for my_str_isnum in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 14:57:42 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      ++i;
    }
  return (1);
}
