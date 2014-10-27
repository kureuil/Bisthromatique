/*
** my_power_rec.c for my_power_rec in /home/rius_b/rendu/Piscine_C_J05
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct  3 09:10:21 2014 brendan rius
** Last update Thu Oct  9 09:39:56 2014 brendan rius
*/

int	my_power_rec(int nb, int power)
{
  int	tmp;
  int	tmp_squared;

  if (power < 0)
   return (0);
  if (power == 0)
    return (1);
  if (nb == 2)
    return (1 << power);
  tmp = my_power_rec(nb, power >> 1);
  if (mult_will_overflow(tmp, tmp))
    return (0);
  tmp_squared = tmp * tmp;
  if (power % 2 == 0)
    return (tmp_squared);
  else
    {
      if (mult_will_overflow(tmp_squared, nb))
	return (0);
      return (tmp_squared * nb);
    }
}
