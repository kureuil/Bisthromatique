/*
** my_is_prime.c for my_is_prime in /home/rius_b/rendu/Piscine_C_J05
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct  3 12:17:25 2014 brendan rius
** Last update Thu Oct  9 09:39:56 2014 brendan rius
*/

int	compute_prime(int min, int max, int n, int previous)
{
  long	median;
  long	median_squared;

  median = ((long) min + (long) max) / 2;
  median_squared = median * median;
  if (median == previous && previous != -1)
    return (median);
  if (median_squared == n)
    return ((int) median);
  else if (median_squared > n)
    return (compute(min, median, n, median));
  else
    return (compute(median, max, n, median));
}

int	my_square_root_prime(int nb)
{
  if (nb <= 0)
    return (0);
  return (compute_prime(0, nb, nb, -1));
}

int	my_is_prime(int nb)
{
  int	i;
  int	sqrt_nb;

  if (nb <= 1 || nb % 2 == 0)
    return (0);
  i = 3;
  sqrt_nb = my_square_root_prime(nb) + 1;
  while (i < sqrt_nb)
    {
      if (nb % i == 0)
	return (0);
      i += 2;
    }
  return (1);
}
