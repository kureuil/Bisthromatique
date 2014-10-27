/*
** my_str_isupper.c for my_str_isupper in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 15:21:00 2014 brendan rius
** Last update Thu Oct  9 09:39:50 2014 brendan rius
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] <= 'Z' && str[i] >= 'A'))
	return (0);
      ++i;
    }
  return (1);
}
