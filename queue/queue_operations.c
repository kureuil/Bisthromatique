/*
** queue_operations.c for Bistromathique in /home/rius_b/rendu/Bistromathique/queue
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:55:33 2014 brendan rius
** Last update Mon Oct 27 16:58:51 2014 brendan rius
*/

#include <stdlib.h>
#include "queue.h"
#include "my.h"

void		enqueue(t_queue *queue, void *element)
{
  t_lqueue	*new;

  if (!queue || (new = malloc(sizeof(t_queue))) == NULL)
    {
      my_puterror("Malloc failed. Aborted.\n");
      return;
    }
  new->data = element;
  new->next = NULL;
  if (queue->rear)
    {
      queue->rear->next = new;
      queue->rear = queue->rear->next;
    }
  else
    {
      queue->rear = new;
      queue->front = new;
    }
}

void		dequeue(t_queue *queue)
{
  t_lqueue	*new_front;

  if (!queue || !(queue->front))
    return;
  new_front = queue->front->next;
  free(queue->front);
  queue->front = new_front;
}

void	*front(t_queue *queue)
{
  if (!queue || !(queue->front))
    return (NULL);
  else
    return (queue->front->data);
}

void	*rear(t_queue *queue)
{
  if (!queue || !(queue->rear))
    return (NULL);
  else
    return (queue->rear->data);
}
