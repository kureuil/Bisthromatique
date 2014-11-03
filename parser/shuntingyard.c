/*
** shuntingyard.c for Bistromathique in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Nov  2 14:11:39 2014 Louis Person
** Last update Sun Nov  2 14:22:53 2014 Louis Person
*/

#include <stdlib.h>
#include "stack.h"
#include "bm_base.h"
#include "tokens.h"
#include "postfix.h"

t_rcode		bm_stack_to_output(t_stack **output,
				   t_stack **stack,
				   t_base *base)
{
  t_token	*token;
  t_rcode	ret;

  token = top(*stack);
  pop(stack);
  if ((ret = bm_perfom_op(token, output, base)) != OK)
    return (ret);
  return (OK);
}

t_rcode		bm_handle_operator(t_token *operator,
				   t_stack **output,
				   t_stack **stack,
				   t_base *base)
{
  t_token	*t;
  t_rcode	ret;

  t = top(*stack);
  while  (t != NULL &&
	  ((t->type == OPERATOR &&
	    t->operator.precedence >= operator->operator.precedence) ||
	   (t->type == U_OPERATOR &&
	    t->operator.precedence > operator->operator.precedence)))
    {
      if ((ret = bm_stack_to_output(output, stack, base)) != OK)
	return (ret);
      t = top(*stack);
    }
  push(stack, operator);
  return (OK);
}

t_rcode		bm_handle_rparenthesis(t_stack **output,
				       t_stack **stack,
				       t_base *base)
{
  t_token	*stktop;
  t_rcode	ret;

  stktop = top(*stack);
  while (stktop != NULL &&
	 stktop->type != LPARENTHESIS)
    {
      if ((ret = bm_stack_to_output(output, stack, base)) != OK)
	return (ret);
      stktop = top(*stack);
    }
  if (!stktop)
    return (MISMATCHED_P);
  pop(stack);
  return (OK);
}

t_rcode		bm_shuntingyard(t_stack **output,
				t_stack **op_stack,
				t_token *token,
				t_base *base)
{
  int		ret;

  if (token->type == NUMBER)
    push(output, token);
  else if (bm_token_is_operator(token))
    {
      if ((ret = bm_handle_operator(token, output, op_stack, base)) != OK)
	return (ret);
    }
  else if (token->type == LPARENTHESIS)
    push(op_stack, token);
  else if (token->type == RPARENTHESIS)
    {
      if ((ret = bm_handle_rparenthesis(output, op_stack, base)) != OK)
	return (ret);
    }
  return (OK);
}
