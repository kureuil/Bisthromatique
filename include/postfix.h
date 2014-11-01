/*
** postfix.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:06 2014 brendan rius
** Last update Tue Oct 28 16:17:53 2014 brendan rius
*/

#ifndef POSTFIX_H_
# define POSTFIX_H_

struct s_base;

struct s_token;

struct s_stack;

t_rcode	bm_perfom_op(struct s_token *operator,
		     struct s_stack **op_stack,
		     struct s_stack **output,
		     struct s_base *base);

#endif /* !POSTFIX_H_ */
