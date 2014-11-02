/*
** stack.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:34 2014 brendan rius
** Last update Tue Oct 28 14:48:08 2014 brendan rius
*/

#ifndef STACK_H_
# define STACK_H_

# include "bm_errno.h"

struct s_token;

/*
** Represents a singly-linked list, which is a stack
*/
typedef struct		s_stack
{
  struct s_token	*data;
  struct s_stack	*next;
}			t_stack;

/*
** Push a token to the top of the stack.
** Takes a pointer to a pointer to the first element, so
** it can update it
*/
t_rcode	push(t_stack **top, struct s_token *token);

/*
** Pop an element from the stack, without returning it.
** Takes a pointer to a pointer to the first element, so
** it can update it
*/
void	pop(t_stack **top);

/*
** Return the top element, without poping it
*/
struct s_token	*top(t_stack *top);

#endif /* !STACK_H_ */
