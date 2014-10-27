/*
** my_str_isprintable.c for my_str_isprintable in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 15:24:18 2014 brendan rius
** Last update Thu Oct  9 09:39:50 2014 brendan rius
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] <= 0x7E && str[i] >= 0x20))
	return (0);
      ++i;
    }
  return (1);
}
