/*
** queue.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:16 2014 brendan rius
** Last update Mon Oct 27 15:54:17 2014 brendan rius
*/

#ifndef QUEUES_H_
# define QUEUES_H_

/*
** Represents a generic singly-linked list which is a queue
*/
typedef struct		s_lqueue
{
  void			*data;
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
void	enqueue(t_queue *queue, void *element);

/*
** Dequeue the last element, without returning it.
*/
void	dequeue(t_queue *queue);

/*
** Return the front element, without dequeing it
*/
void	*front(t_queue *queue);

/*
** Return the element at the rear of a queue, without
** dequeuing it.
*/
void	*rear(t_queue *queue);

/*
** Create a new queue and returns it
*/
t_queue	*new_queue();

/*
** Free a queue
*/
void	free_queue(t_queue *queue);

#endif /* !QUEUES_H_ */
