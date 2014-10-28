/*
** div.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:51:57 2014 brendan rius
** Last update Tue Oct 28 15:29:31 2014 brendan rius
*/

#ifndef DIV_H_
# define DIV_H_

struct s_token;

struct s_base;

t_rcode	action_div(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res);

unsigned int	extract_div(char *c, struct s_token *token);

#endif /* !DIV_H_ */
