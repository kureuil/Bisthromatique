/*
** my_getnbr.c for my_getnbr in /home/rius_b/rendu/Piscine_C_J04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  2 08:58:43 2014 brendan rius
** Last update Mon Nov  3 09:32:19 2014 Louis Person
*/

int	my_getnbr(char *str)
{
  int	sign;
  int	nb;

  sign = 1;
  nb = 0;
  while (*str == '+' || *str == '-')
    sign *= (*str++  == '-' ? -1 : 1);
  while (*str >= '0' && *str <= '9')
  {
    if (nb < (-2147483648 / 10) || nb > (2147483647 / 10))
      return (0);
    nb *= 10;
    if (nb < -2147483648 + (*str - '0') || nb > 2147483647 - (*str - '0'))
      return (0);
    nb += ((*str - '0') * sign);
    str++;
  }
  return (nb);
}
