/*
** my_getnbr_base.c for my_getnbr_base in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 19:34:41 2014 brendan rius
** Last update Sun Oct 26 23:12:54 2014 brendan rius
*/

int	is_unique(char *str, int len)
{
  int	i;

  i = 0;
  while (str[i++])
    {
      if (str[i] == str[i - 1])
	return (0);
    }
  return (1);
}

int	idx(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      ++i;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	len_base;
  char	multiplier;
  int	nb;
  int	tmp;
  int	tmp2;

  multiplier = (len_base = nb = 0) + 1;
  while (base[++len_base] != '\0');
  if (!is_unique(base, len_base))
    return (0);
  while (*str == '+' || *str == '-')
    multiplier *= (*str++ == '-') ? -1 : 1;
  while (idx(base, *str) != -1)
    {
      if (mult_will_overflow(nb, len_base))
	return (0);
      tmp = nb * len_base;
      tmp2 = idx(base, *str++);
      if (add_will_overflow(tmp, tmp2))
	return (0);
      nb = tmp + tmp2;
    }
  return (mult_will_overflow(nb, multiplier) ? 0 : nb * multiplier);
}
