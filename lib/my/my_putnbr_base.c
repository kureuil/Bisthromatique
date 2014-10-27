/*
** my_putnbr_base.c for my_putnbr_base in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 15:30:28 2014 brendan rius
** Last update Thu Oct  9 09:39:55 2014 brendan rius
*/

int	my_putnbr_base(int nbr, char *base)
{
  int	len;

  if (!base)
    return (0);
  len = my_strlen(base);
  if (nbr < 0)
    my_putchar('-');
  if (nbr > len - 1 || nbr < - (len - 1))
    my_putnbr_base(nbr < 0 ? - (nbr / len) : nbr / len, base);
  my_putchar(nbr < 0 ? base[- nbr % len] : base[nbr % len]);
}
