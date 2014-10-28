/*
** mul.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:52:58 2014 brendan rius
** Last update Tue Oct 28 15:26:52 2014 brendan rius
*/

#ifndef MUL_H_
# define MUL_H_

struct s_token;

t_rcode	action_mul(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res);

unsigned int	extract_mul(char *c, struct s_token *token);

#endif /* !MUL_H_ */
