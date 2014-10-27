/*
** my_str_islower.c for my_str_islower.c in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 15:03:19 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] <= 'z' && str[i] >= 'a'))
	return (0);
      ++i;
    }
  return (1);
}
