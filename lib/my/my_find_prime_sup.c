/*
** my_find_prime_sup.c for my_find_prime_sup in /home/rius_b/rendu/Piscine_C_J05
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Oct  4 16:20:37 2014 brendan rius
** Last update Thu Oct  9 09:39:57 2014 brendan rius
*/

int	my_find_prime_sup(int nb)
{
  int	i;

  if (my_is_prime(nb))
    return (nb);
  if (nb % 2)
    i = nb + 2;
  else
    i = nb + 1;
  while (!my_is_prime(i))
    {
      if (i > ( 1 << (((unsigned int) (sizeof(int) * 8 - 1)) - 1)) - 1)
	return (0);
      ++i;
    }
  return (i);
}
