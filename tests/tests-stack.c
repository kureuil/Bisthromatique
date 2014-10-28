/*
** tests-stack.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:00:00 2014 brendan rius
** Last update Tue Oct 28 15:45:18 2014 brendan rius
*/

#include <stdlib.h>
#include "stack.h"
#include "my.h"
#include "tokenizer.h"

int		main(int argc, char **argv)
{
  int		i;
  t_stack	*stack;
  t_token	*token;

  stack = NULL;
  i = 0;
  while (i < argc)
    {
      token = new_token();
      token->string_value = argv[i];
      push(&stack, token);
      ++i;
    }
  while ((token = top(stack)) != NULL)
    {
      my_putstr(token->string_value);
      my_putchar('\n');
      pop(&stack);
    }
  return (0);
}
