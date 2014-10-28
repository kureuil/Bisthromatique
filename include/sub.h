/*
** sub.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:43 2014 brendan rius
** Last update Tue Oct 28 15:26:30 2014 brendan rius
*/

#ifndef SUB_H_
# define SUB_H_

struct s_token;

t_rcode	action_sub(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res);

unsigned int	extract_sub(char *c, struct s_token *token, struct s_token *p);

#endif /* !SUB_H_ */
