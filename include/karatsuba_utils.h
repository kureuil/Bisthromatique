/*
** karatsuba_utils.h for Bistromathique in /home/brendan/rendu/Bistromathique
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Nov  6 15:28:43 2014 Brendan Rius
** Last update Thu Nov  6 15:28:43 2014 Brendan Rius
*/

#ifndef KARATSUBA_UTILS_H_
# define KARATSUBA_UTILS_H_

# include "bm_errno.h"

struct s_base;

struct s_token;

typedef struct		s_karat_coeff
{
  struct s_token	*z0;
  struct s_token	*z1;
  struct s_token	*z2;
}			t_karat_coeff;

typedef struct		s_delimiters
{
  struct s_token	*a;
  struct s_token	*b;
  struct s_token	*c;
  struct s_token	*d;
}			t_delimiters;

t_rcode	pad(struct s_token *t,
	    struct s_base *base,
	    int nb,
	    struct s_token *res);

t_rcode	split_token(struct s_token *n1,
		    struct s_token *n2,
		    t_delimiters *delimiters,
		    struct s_base *base);
#endif /* !KARATSUBA_UTILS_H_ */
