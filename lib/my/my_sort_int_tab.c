/*
** my_sort_int_tab.c for my_sort_int_tab in /home/rius_b/rendu/Piscine_C_J04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  2 10:51:55 2014 brendan rius
** Last update Thu Oct  9 09:39:55 2014 brendan rius
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;

  if (!tab)
    return;
  i = 0;
  j = 0;
  while (i < size)
    {
      j = i;
      while (j > 0 && tab[j] < tab[j - 1])
	{
	  my_swap(&tab[j - 1], &tab[j]);
	  --j;
	}
      ++i;
    }
}
