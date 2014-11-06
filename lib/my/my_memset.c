/*
** my_memset.c for my_memset in /home/rius_b/rendu/Piscine_C_eval_expr
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Oct 22 16:22:06 2014 brendan rius
** Last update Thu Oct 30 14:21:00 2014 brendan rius
*/

void	*my_memset(void *s, char c, int n)
{
  char	*sc;

  sc = (char *) s;
  while (n)
    {
      *(sc + n - 1) = c;
      --n;
    }
  return (s);
}
