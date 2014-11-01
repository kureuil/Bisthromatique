/*
** shuntingyard.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:25 2014 brendan rius
** Last update Tue Oct 28 13:35:05 2014 brendan rius
*/

#ifndef SHUNTINGYARD_H_
# define SHUNTINGYARD_H_

# include "bm_errno.h"

struct s_base;

struct s_token;

struct s_stack;

t_rcode	bm_stack_to_output(struct s_stack **output,
			   struct s_stack **stack,
			   struct s_base *base);

void	bm_handle_operator(struct s_token *operator,
			   struct s_stack **output,
			   struct s_stack **stack,
			   struct s_base *base);

t_rcode	bm_handle_rparenthesis(struct s_stack **output,
			       struct s_stack **stack,
			       struct s_base *base);

t_rcode	bm_shuntingyard(struct s_stack **output,
			struct s_stack **op_stack,
			struct s_token *token,
			struct s_base *base);

#endif /* !SHUNTINGYARD_H_ */
