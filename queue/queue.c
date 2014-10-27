/*
** queue.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:07 2014 brendan rius
** Last update Mon Oct 27 16:56:13 2014 brendan rius
*/

#include <stdlib.h>
#include "my.h"
#include "queue.h"

t_queue		*new_queue()
{
  t_queue	*queue;

  if ((queue = malloc(sizeof(t_queue))) == NULL)
    return (NULL);
  queue->front = NULL;
  queue->rear = NULL;
  return (queue);
}

void	free_queue(t_queue *queue)
{
  t_lqueue	*next;

  while (queue->front)
    {
      next = queue->front->next;
      free(queue->front);
      queue->front = next;
    }
  free(queue);
}
