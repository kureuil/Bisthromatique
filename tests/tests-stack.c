/*
** tests-stack.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:00:00 2014 brendan rius
** Last update Mon Oct 27 16:00:00 2014 brendan rius
*/

#include <stdlib.h>
#include "stack.h"
#include "my.h"

int		main(int argc, char **argv)
{
  int		i;
  t_stack	*stack;
  void		*data;

  stack = NULL;
  i = 0;
  while (i < argc)
    {
      push(&stack, argv[i]);
      ++i;
    }
  while ((data = top(stack)) != NULL)
    {
      my_putstr((char *) data);
      my_putchar('\n');
      pop(&stack);
    }
  return (0);
}
