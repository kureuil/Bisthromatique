/*
** postfix.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:58:57 2014 brendan rius
** Last update Mon Oct 27 16:01:11 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "queue.h"
#include "stack.h"
#include "my.h"

void	binary_op(t_token *token, t_stack **stack)
{
  int	(*fct)();
  int	n1;

  fct = token->value.operator.action;
  token = (t_token *) top(*stack);
  n1 = token->value.int_value;
  pop(stack);
  token = (t_token *) top(*stack);
  pop(stack);
  token->value.int_value = (*fct)(token->value.int_value, n1);
  push(stack, token);
}

void	unary_op(t_token *token, t_stack **stack)
{
  int	(*fct)();

  fct = token->value.operator.action;
  token = (t_token *) top(*stack);
  pop(stack);
  token->value.int_value = (*fct)(token->value.int_value);
  push(stack, token);
}

int		eval_postfix(t_queue *rpn)
{
  void		*data;
  t_token	*token;
  t_stack	*stack;

  stack = NULL;
  while ((data = front(rpn)))
    {
      dequeue(rpn);
      token = (t_token *) data;
      if (token->type == NUMBER)
	{
	  token->value.int_value = my_getnbr(token->string_value);
	  push(&stack, token);
	}
      else if (token->type == OPERATOR)
	binary_op(token, &stack);
      else if (token->type == U_OPERATOR)
	unary_op(token, &stack);
    }
  return (((t_token *) top(stack))->value.int_value);
}

void		display_rpn(t_queue *rpn)
{
  void		*data;
  t_token	*token;

  while ((data = front(rpn)))
    {
      dequeue(rpn);
      token = (t_token *) data;
      my_putstr(token->string_value);
      my_putstr(token->type == U_OPERATOR ? "u" : "b");
      my_putchar(' ');
    }
}
