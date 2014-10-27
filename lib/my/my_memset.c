/*
** my_memset.c for my_memset in /home/rius_b/rendu/Piscine_C_eval_expr
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Oct 22 16:22:06 2014 brendan rius
** Last update Wed Oct 22 16:26:08 2014 brendan rius
*/

void	*my_memset(void *s, char c, int n)
{
  while (n--)
    *((char*) s) = c;
  return (s);
}
