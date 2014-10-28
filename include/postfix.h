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

struct s_queue;

struct s_base;

struct s_token;

t_rcode	eval_postfix(struct s_queue *rpn,
		       struct s_token **res,
		       struct s_base *base);

void	display_rpn(t_queue *rpn);

#endif /* !POSTFIX_H_ */
