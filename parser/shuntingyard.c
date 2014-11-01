#include <stdlib.h>
#include "stack.h"
#include "bm_base.h"
#include "tokens.h"

t_rcode		bm_stack_to_output(t_stack **output,
				   t_stack **stack,
				   t_base *base)
{
  t_token	*token;
  t_token	*n1;
  t_token	*n2;
  t_token	*res;
  t_rcode	ret;

  token = top(*stack);
  pop(stack);
  if (bm_token_is_operator(token))
    {
      if ((ret = bm_perfom_op(token, output, base)) != OK)
	return (ret);
    }
  else
    push(output, token);
  return (OK);
}

void		bm_handle_operator(t_token *operator,
				   t_stack **output,
				   t_stack **stack,
				   t_base *base)
{
  t_token	*t;

  t = top(*stack);
  while  (t != NULL &&
	  ((t->type == OPERATOR && t->operator.precedence >= operator->operator.precedence) ||
	   (t->type == U_OPERATOR && t->operator.precedence > operator->operator.precedence)))
    {
      bm_stack_to_output(output, stack, base);
      t = top(*stack);
    }
  push(stack, operator);
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
    bm_handle_operator(token, output, op_stack, base);
  else if (token->type == LPARENTHESIS)
    push(op_stack, token);
  else if (token->type == RPARENTHESIS)
    {
      if ((ret = bm_handle_rparenthesis(output, op_stack, base)) != OK)
	return (ret);
    }
  return (OK);
}
