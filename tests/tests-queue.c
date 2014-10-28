/*
** tests-queue.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:52 2014 brendan rius
** Last update Tue Oct 28 17:59:04 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "queue.h"
#include "my.h"

int		main(int argc, char **argv)
{
  int		i;
  t_queue	*queue;
  t_token	*token;

  i = 0;
  queue = NULL;
  init_queue(&queue);
  while (i < argc)
    {
      token = new_token();
      token->string_value = argv[i];
      enqueue(queue, token);
      ++i;
    }
  while ((token = front(queue)) != NULL)
    {
      my_putstr(token->string_value);
      my_putchar('\n');
      dequeue(queue);
    }
  free_queue(queue);
  return (0);
}
