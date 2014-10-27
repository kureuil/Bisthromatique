/*
** shuntingyard.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:15 2014 brendan rius
** Last update Mon Oct 27 18:24:19 2014 brendan rius
*/

#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "tokenizer.h"
#include "my.h"

char	is_operator(t_token *token)
{
  return (token->type == OPERATOR || token->type == U_OPERATOR);
}

void	stack_to_queue(t_queue *queue, t_stack **stack)
{
  enqueue(queue, (t_token *) top(*stack));
  pop(stack);
}

void		handle_operator(t_token *operator,
				t_queue *queue,
				t_stack **stack)
{
  t_token	*t;

  t = (t_token *) top(*stack);
  while  (t != NULL && is_operator(t) &&
	  t->value.operator.precedence > operator->value.operator.precedence)
    {
      stack_to_queue(queue, stack);
      t = (t_token *) top(*stack);
    }
  push(stack, operator);
}

void		handle_rparenthesis(t_queue *queue, t_stack **stack)
{
  t_token	*stktop;

  stktop = (t_token *) top(*stack);
  while (stktop != NULL &&
	 stktop->type != LPARENTHESIS)
    {
      stack_to_queue(queue, stack);
      stktop = (t_token *) top(*stack);
    }
  pop(stack);
}

t_queue		*shuntingyard(t_queue *tokens)
{
  t_token	*token;
  t_queue	*queue;
  t_stack	*stack;

  queue = new_queue();
  stack = NULL;
  while ((token = (t_token *) front(tokens)) != NULL)
    {
      if (token->type == NUMBER)
	enqueue(queue, token);
      else if (is_operator(token))
	handle_operator(token, queue, &stack);
      else if (token->type == LPARENTHESIS)
	push(&stack, token);
      else if (token->type == RPARENTHESIS)
	handle_rparenthesis(queue, &stack);
      dequeue(tokens);
    }
  while ((token = ((t_token *) top(stack))) != NULL && is_operator(token))
    stack_to_queue(queue, &stack);
  free_stack(&stack);
  return (queue);
}
