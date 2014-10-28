/*
** queue.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:16 2014 brendan rius
** Last update Tue Oct 28 16:10:01 2014 brendan rius
*/

#ifndef QUEUES_H_
# define QUEUES_H_

# include "bm_errno.h"

struct s_token;

/*
** Represents a generic singly-linked list which is a queue
*/
typedef struct		s_lqueue
{
  struct s_token	*token;
  struct s_lqueue	*next;
}			t_lqueue;

typedef struct		s_queue
{
  t_lqueue		*front;
  t_lqueue		*rear;
}			t_queue;

/*
** Add an element at the rear of the queue.
** Takes a pointer to a pointer to the last element, so that
** it changes it.
*/
t_rcode	enqueue(t_queue *queue, struct s_token *token);

/*
** Dequeue the last element, without returning it.
*/
void	dequeue(t_queue *queue);

/*
** Return the front element, without dequeing it
*/
struct s_token	*front(t_queue *queue);

/*
** Return the element at the rear of a queue, without
** dequeuing it.
*/
struct s_token	*rear(t_queue *queue);

/*
** Init a queue and returns it
*/
t_rcode	init_queue(t_queue **queue);

/*
** Free a queue
*/
void	free_queue(t_queue *queue);

#endif /* !QUEUES_H_ */
