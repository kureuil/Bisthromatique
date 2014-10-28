/*
** shuntingyard.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:15 2014 brendan rius
** Last update Tue Oct 28 14:57:42 2014 brendan rius
*/

#include <stdlib.h>
#include "boolean.h"
#include "queue.h"
#include "stack.h"
#include "tokenizer.h"
#include "my.h"
#include "bm_errno.h"
#include "shuntingyard.h"

char	is_operator(t_token *token)
{
  return (token->type == OPERATOR || token->type == U_OPERATOR);
}

void	stack_to_queue(t_queue *queue, t_stack **stack)
{
  enqueue(queue, top(*stack));
  pop(stack);
}

void		handle_operator(t_token *operator,
				t_queue *queue,
				t_stack **stack)
{
  t_token	*t;

  t = top(*stack);
  while  (t != NULL &&
	  ((t->type == OPERATOR && t->operator.precedence >= operator->operator.precedence) ||
	   (t->type == U_OPERATOR && t->operator.precedence > operator->operator.precedence)))
    {
      stack_to_queue(queue, stack);
      t = (t_token *) top(*stack);
    }
  push(stack, operator);
}

t_rcode		handle_rparenthesis(t_queue *queue, t_stack **stack)
{
  t_token	*stktop;

  stktop = top(*stack);
  while (stktop != NULL &&
	 stktop->type != LPARENTHESIS)
    {
      stack_to_queue(queue, stack);
      stktop = top(*stack);
    }
  if (!stktop)
    return (MISMATCHED_P);
  pop(stack);
  return (OK);
}

t_rcode		shuntingyard(t_queue *tokens, t_queue *output)
{
  t_token	*token;
  t_stack	*stack;
  int		ret;

  stack = NULL;
  while ((token = front(tokens)) != NULL)
    {
      if (token->type == NUMBER)
	enqueue(output, token);
      else if (is_operator(token))
	handle_operator(token, output, &stack);
      else if (token->type == LPARENTHESIS)
	push(&stack, token);
      else if (token->type == RPARENTHESIS)
	{
	  if ((ret = handle_rparenthesis(output, &stack)) != OK)
	    return (ret);
	}
      dequeue(tokens);
    }
  while ((token = top(stack)) != NULL)
    {
      if (token->type == LPARENTHESIS || token->type == RPARENTHESIS)
	{
	  free_stack(&stack);
	  return (MISMATCHED_P);
	}
      stack_to_queue(output, &stack);
    }
  free_stack(&stack);
  return (OK);
}
