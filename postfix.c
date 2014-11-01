/*
** postfix.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:58:57 2014 brendan rius
** Last update Sat Nov  1 16:19:08 2014 Louis Person
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "queue.h"
#include "stack.h"
#include "my.h"
#include "bm_errno.h"
#include "bm_base.h"

/*
** Can be optimized by not poping the last number, using it as the result.
** TODO: check errcode (division by zero...).
** THIS FUNCTION DOES NOT FREE USED TOKENS, IT IS OPERATIONS' ROLE (in order
** to increase perfs)
*/
t_rcode		binary_op(t_token *token, t_stack **stack, t_base *base)
{
  t_rcode	(*fct)();
  t_token	*n1;
  t_token	*n2;
  t_token	*res;
  t_rcode	ret;

  res = NULL;
  if ((ret = bm_new_token(&res)) != OK)
    return (ret);
  fct = token->operator.action;
  token = top(*stack);
  if (token == NULL)
    return (NOT_ENOUGH_VALUES);
  n2 = token;
  pop(stack);
  token = top(*stack);
  if (token == NULL)
    return (NOT_ENOUGH_VALUES);
  n1 = token;
  pop(stack);
  (*fct)(base, n1, n2, res);
  push(stack, res);
  return (OK);
}

/*
** Can be optimized by not poping the last number, but using it as the result.
** TODO: check errcode
*/
t_rcode		unary_op(t_token *token, t_stack **stack, t_base *base)
{
  t_rcode	(*fct)();
  t_token	*n;
  t_token	*res;
  t_rcode	ret;

  res = NULL;
  if ((ret = bm_new_token(&res)) != OK)
    return (ret);
  fct = token->operator.action;
  token = top(*stack);
  if (token == NULL)
    return (NOT_ENOUGH_VALUES);
  n = token;
  pop(stack);
  (*fct)(base, n, res);
  push(stack, res);
  return (OK);
}

t_rcode		eval_postfix(t_queue *rpn, t_token **res, t_base *base)
{
  t_token	*token;
  t_stack	*stack;
  int		ret;

  stack = NULL;
  while ((token = front(rpn)))
    {
      dequeue(rpn);
      if (token->type == NUMBER)
	push(&stack, token);
      else if (token->type == OPERATOR)
	{
	  if ((ret = binary_op(token, &stack, base)) != OK)
	    return (ret);
	}
      else if (token->type == U_OPERATOR)
	{
	  if ((ret = unary_op(token, &stack, base)) != OK)
	    return (ret);
	}
    }
  token = top(stack);
  pop(&stack);
  if (!token)
    return (NOT_ENOUGH_VALUES);
  if (top(stack))
    return (TOO_MUCH_VALUES);
  else
    *res = token;
  return (OK);
}

void		display_rpn(t_queue *rpn)
{
  t_token	*token;

  while ((token = front(rpn)))
    {
      dequeue(rpn);
      my_putstr(token->string_value);
      my_putstr(token->type == U_OPERATOR ? "u" : "b");
      my_putchar(' ');
    }
}
