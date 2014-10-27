/*
** tests-queue.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:52 2014 brendan rius
** Last update Mon Oct 27 15:59:52 2014 brendan rius
*/

#include <stdlib.h>
#include "queue.h"
#include "my.h"

int		main(int argc, char **argv)
{
  int		i;
  t_queue	*queue;
  void		*data;

  i = 0;
  queue = new_queue();
  while (i < argc)
    {
      enqueue(queue, argv[i]);
      ++i;
    }
  while ((data = front(queue)) != NULL)
    {
      my_putstr((char *) data);
      my_putchar('\n');
      dequeue(queue);
    }
  free_queue(queue);
  return (0);
}
