/*
** my_put_nbr.c for my_put_nbr in /home/rius_b/rendu/Piscine_C_J03
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Oct  1 11:54:38 2014 brendan rius
** Last update Thu Oct  9 09:31:40 2014 brendan rius
*/

int	my_put_nbr(int n)
{
  if (n < 0)
    my_putchar('-');
  if (n > 9 || n < -9)
    my_put_nbr(n < 0 ? - (n / 10) : n / 10);
  my_putchar((n < 0 ? - (n % 10) : n % 10) + '0');
}
