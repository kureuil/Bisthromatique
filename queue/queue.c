/*
** queue.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:07 2014 brendan rius
** Last update Tue Oct 28 16:09:49 2014 brendan rius
*/

#include <stdlib.h>
#include "my.h"
#include "queue.h"
#include "bm_errno.h"

t_rcode	init_queue(t_queue **queue)
{
  if (!(*queue = malloc(sizeof(t_queue))))
    return (COULD_NOT_MALLOC);
  (*queue)->front = NULL;
  (*queue)->rear = NULL;
  return (OK);
}

void		free_queue(t_queue *queue)
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
