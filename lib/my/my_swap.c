/*
** my_swap.c for my_swap.c in /home/rius_b/rendu/Piscine_C_J04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  2 08:44:45 2014 brendan rius
** Last update Thu Oct  9 09:39:49 2014 brendan rius
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  if (!a || !b)
    return;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
