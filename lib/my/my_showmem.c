/*
** my_showmem.c for my_showmem in /home/rius_b/rendu/Piscine_C_J07/ex_01
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct  7 10:26:09 2014 brendan rius
** Last update Thu Oct  9 09:39:55 2014 brendan rius
*/

void		my_mem_print_address(char *str)
{
  int		nb_zeros;
  unsigned long address;

  address = (unsigned long) str;
  if (address <= 0xF)
    nb_zeros = 7;
  else if (address > 0xF && address <= 0xFF)
    nb_zeros = 6;
  else if (address > 0xFF && address <= 0xFFF)
    nb_zeros = 5;
  else if (address > 0xFF && address <= 0xFFF)
    nb_zeros = 4;
  else if (address > 0xFFF && address <= 0xFFFF)
    nb_zeros = 3;
  else if (address > 0xFFFFF && address <= 0xFFFFFF)
    nb_zeros = 2;
  else if (address > 0xFFFFFF && address <= 0xFFFFFFF)
    nb_zeros = 1;
  else
    nb_zeros = 0;
  while (nb_zeros--)
    my_putchar('0');
  my_putnbr_base(address, "0123456789abcdef");
  my_putchar(':');
  my_putchar(' ');
}

void		my_mem_print_hex(char *str, int size)
{
  int		whitespace;
  unsigned char	c;
  int		i;
  int		nb_written;

  whitespace = nb_written = 0;
  while (size--)
    {
      c = (unsigned char) *str++;
      if (c <= 0xF)
	my_putchar('0');
      my_putnbr_base(c, "0123456789abcdef");
      nb_written += 2;
      if (!whitespace)
	whitespace = 1;
      else
	{
	  my_putchar(' ');
	  ++nb_written;
	  whitespace = 0;
	}
    }
  i = 40 - nb_written;
  while (i--)
    my_putchar(' ');
}

void	my_mem_print_str(char *str, int size)
{
  unsigned char c;

  while (size--)
    {
      c = (unsigned char) *str++;
      if (c >= ' ' && c <= '~')
	my_putchar(c);
      else
	my_putchar('.');
    }
}

int	my_showmem(char *str, int size)
{
  if (!str)
    return (0);
  while (size > 0)
    {
      my_mem_print_address(str);
      my_mem_print_hex(str, size - 16 >= 0 ? 16 : size);
      my_mem_print_str(str, size - 16 >= 0 ? 16 : size);
      my_putchar('\n');
      str += 16;
      size -= 16;
    }
  return (0);
}
