/*
** mod.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:52:49 2014 brendan rius
** Last update Tue Oct 28 15:33:16 2014 brendan rius
*/

#ifndef MOD_H_
# define MOD_H_

struct s_token;

struct s_base;

t_rcode	action_mod(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res);

unsigned int	extract_mod(char *c,
			    struct s_token *token);

#endif /* !MOD_H_ */
