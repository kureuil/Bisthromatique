/*
** my_strcmp.c for my_strcmp in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 09:06:36 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  while (*(s1 + i) == *(s2 + i))
    {
      if (*(s1 + i) == '\0')
	return (0);
      ++i;
    }
  if (*(s1 + i) < *(s2 + i))
    return (-1);
  else
    return (1);
}
