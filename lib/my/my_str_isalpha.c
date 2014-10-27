/*
** my_str_isalpha.c for my_str_isalpha in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 14:47:07 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

int	is_alpha(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!is_alpha(str[i]))
	return (0);
      ++i;
    }
  return (1);
}
