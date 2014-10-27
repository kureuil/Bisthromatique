/*
** my_square_root.c for my_square_root in /home/rius_b/rendu/Piscine_C_J05
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct  3 11:43:50 2014 brendan rius
** Last update Thu Oct  9 09:39:52 2014 brendan rius
*/

int	compute(int min, int max, int n, int previous)
{
  long	median;
  long	median_squared;

  median = ((long) min + (long) max) / 2;
  median_squared = median * median;
  if (median == previous && previous != -1)
    return (0);
  if (median_squared == n)
    return ((int) median);
  else if (median_squared > n)
    return (compute(min, median, n, median));
  else
    return (compute(median, max, n, median));
}

int	my_square_root(int nb)
{
  if (nb <= 0)
    return (0);
  return (compute(0, nb, nb, -1));
}
