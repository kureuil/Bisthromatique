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

# include "queue.h"
# include "bm_errno.h"

t_rcode	shuntingyard(t_queue *tokens, t_queue *output);

#endif /* !SHUNTINGYARD_H_ */
