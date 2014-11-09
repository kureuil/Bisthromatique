/*
** karatsuba_split.h for Bistromathique in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Nov  9 22:58:31 2014 Louis Person
** Last update Sun Nov  9 23:06:00 2014 Louis Person
*/

#ifndef KARATSUBA_SPLIT_H_
# define KARATSUBA_SPLIT_H_

struct s_delimiters;
struct s_token;
struct s_base;

void	make_delimiters_static(struct s_delimiters);

void	split_token(struct s_token,
		    struct s_token,
		    struct s_delimiters,
		    struct s_base);

t_rcode	split_tokens(struct s_token *,
		     struct s_token *,
		     struct s_delimiters *,
		     struct s_base *);

#endif /* !KARATSUBA_SPLIT_H_ */
