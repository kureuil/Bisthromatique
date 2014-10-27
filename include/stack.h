/*
** stack.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:34 2014 brendan rius
** Last update Mon Oct 27 15:54:35 2014 brendan rius
*/

#ifndef STACK_H_
# define STACK_H_

/*
** Represents a singly-linked list, which is a stack
*/
typedef struct		s_stack
{
  void			*data;
  struct s_stack	*next;
}			t_stack;

/*
** Push an element to the top of the stack.
** Takes a pointer to a pointer to the first element, so
** it can update it
*/
void	push(t_stack **top, void *data);

/*
** Pop an element from the stack, without returning it.
** Takes a pointer to a pointer to the first element, so
** it can update it
*/
void	pop(t_stack **top);

/*
** Return the top element, without poping it
*/
void	*top(t_stack *top);

/*
** Free a stack from its top.
*/
void	free_stack(t_stack **top);

#endif /* !STACK_H_ */
