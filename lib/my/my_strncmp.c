/*
** my_strncmp.c for my_strncmp in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 11:10:01 2014 brendan rius
** Last update Tue Oct 21 13:55:55 2014 brendan rius
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  char	c1;
  char	c2;

  while (n > 0)
    {
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0' || c1 != c2)
	return c1 - c2;
      n--;
    }
  return (c1 - c2);
}
