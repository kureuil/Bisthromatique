/*
** postfix.c for Bistromathique in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Nov  2 14:10:36 2014 Louis Person
** Last update Sun Nov  2 14:10:37 2014 Louis Person
*/

#include <stdlib.h>
#include "stack.h"
#include "bm_base.h"
#include "tokens.h"

t_rcode		unary_op(t_token *token,
			 t_stack **stack,
			 t_base *base,
			 t_token *res)
{
  t_token	*n;
  t_rcode	ret;

  if ((n = top(*stack)) == NULL)
    return (NOT_ENOUGH_VALUES);
  pop(stack);
  if ((ret = (*(token->operator.action))(base, n, res)) != OK)
    return (ret);
  return (OK);
}

t_rcode		binary_op(t_token *token,
			  t_stack **stack,
			  t_base *base,
			  t_token *res)
{
  t_token	*n1;
  t_token	*n2;
  t_rcode	ret;

  if ((n2 = top(*stack)) == NULL)
    return (NOT_ENOUGH_VALUES);
  pop(stack);
  if ((n1 = top(*stack)) == NULL)
    return (NOT_ENOUGH_VALUES);
  pop(stack);
  if ((ret = (*(token->operator.action))(base, n1, n2, res)) != OK)
    return (ret);
  return (OK);
}

t_rcode		bm_perfom_op(t_token *operator,
			     t_stack **output,
			     t_base *base)
{
  t_token	*res;
  t_rcode	ret;

  if ((ret = bm_new_token(&res)) != OK)
    return (ret);
  res->type = NUMBER;
  if (operator->type == OPERATOR)
    {
      if ((ret = binary_op(operator, output, base, res)) != OK)
	return (ret);
    }
  else if (operator->type == U_OPERATOR)
    {
      if ((ret = unary_op(operator, output, base, res)) != OK)
	return (ret);
    }
  push(output, res);
  bm_free_token(operator);
  return (OK);
}
