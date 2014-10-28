/*
** negate.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:53:27 2014 brendan rius
** Last update Tue Oct 28 15:37:51 2014 brendan rius
*/

#ifndef NEGATE_H_
# define NEGATE_H_

struct s_token;

struct s_base;

t_rcode	action_negate(struct s_base *base,
		      struct s_token *n,
		      struct s_token *res);

unsigned int	extract_negate(char *c, struct s_token *token);

#endif /* !NEGATE_H_ */
