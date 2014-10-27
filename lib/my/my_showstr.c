/*
** my_showstr.c for my_showstr in /home/rius_b/rendu/Piscine_C_J06/ex_17
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct  7 08:28:34 2014 brendan rius
** Last update Thu Oct  9 09:39:55 2014 brendan rius
*/

int	my_char_isprintable(char c)
{
  return (c <= 0x7E && c >= 0x20);
}

void	my_put_special_char(char c)
{
  my_putchar('\\');
  if (c <= 15)
    my_putchar('0');
  my_putnbr_base(c, "0123456789abcdef");
}

int	my_showstr(char *str)
{
  if (!str)
    return;
  while (*str)
    {
      if (my_char_isprintable(*str))
	my_putchar(*str++);
      else
	my_put_special_char(*str++);
    }
}
