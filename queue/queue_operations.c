/*
** queue_operations.c for Bistromathique in /home/rius_b/rendu/Bistromathique/queue
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:55:33 2014 brendan rius
** Last update Tue Oct 28 15:14:49 2014 brendan rius
*/

#include <stdlib.h>
#include "queue.h"
#include "my.h"

struct s_token;

t_rcode		enqueue(t_queue *queue, struct s_token *token)
{
  t_lqueue	*new;

  if (!queue || (new = malloc(sizeof(t_queue))) == NULL)
    return (COULD_NOT_MALLOC);
  new->token = token;
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
  return (OK);
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

struct s_token	*front(t_queue *queue)
{
  if (!queue || !(queue->front))
    return (NULL);
  else
    return (queue->front->token);
}

struct s_token	*rear(t_queue *queue)
{
  if (!queue || !(queue->rear))
    return (NULL);
  else
    return (queue->rear->token);
}
