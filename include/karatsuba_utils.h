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

t_rcode	pow_base(struct s_base *base,
		 int multiplier,
		 struct s_token *res);

t_rcode	split_token(struct s_token *src,
		    int sep,
		    struct s_token *first,
		    struct s_token *second);

#endif /* !KARATSUBA_UTILS_H_ */
