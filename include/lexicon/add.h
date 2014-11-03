/*
** add.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:51:46 2014 brendan rius
** Last update Tue Oct 28 15:25:29 2014 brendan rius
*/

#ifndef ADD_H_
# define ADD_H_

# include "bm_errno.h"

struct s_token;

struct s_base;

t_rcode	action_add(struct s_base *base,
		   struct s_token *n1,
		   struct s_token *n2,
		   struct s_token *res);

t_rcode	extract_add(char *,
		    struct s_token *,
		    struct s_base *,
		    struct s_token *);

t_rcode	action_add_compute(struct s_base *base,
			   struct s_token *n1,
			   struct s_token *n2,
			   struct s_token *res);

t_rcode	action_unary_plus(struct s_base *base,
			  struct s_token *n,
			  struct s_token *res);

t_rcode	extract_unary_plus(char *,
			   struct s_token *);

#endif /* !ADD_H_ */
