/*
** unary_plus.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 17:20:10 2014 brendan rius
** Last update Tue Oct 28 15:40:31 2014 brendan rius
*/

#ifndef UNARY_PLUS_H_
# define UNARY_PLUS_H_

struct s_token;

struct s_base;

t_rcode	action_unary_plus(struct s_base *base,
			  struct s_token *n,
			  struct s_token *res);

unsigned int	extract_unary_plus(char *, struct s_token *);

#endif /* !UNARY_PLUS_H_ */
