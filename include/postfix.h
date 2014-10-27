/*
** postfix.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:06 2014 brendan rius
** Last update Mon Oct 27 16:01:51 2014 brendan rius
*/

#ifndef POSTFIX_H_
# define POSTFIX_H_

# include "queue.h"

int	eval_postfix(t_queue *rpn);

void	display_rpn(t_queue *rpn);

#endif /* !POSTFIX_H_ */
