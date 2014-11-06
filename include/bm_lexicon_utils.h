/*
** bm_lexicon_utils.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:55:31 2014 brendan rius
** Last update Sun Nov  2 17:04:17 2014 Louis Person
*/

#ifndef BM_LEXICON_UTILS_H_
# define BM_LEXICON_UTILS_H_

struct s_base;

struct s_token;

/*
** Reorder tokens so that the bigger one is the firt
*/
void	reorder_tokens(struct s_token **n1,
		       struct s_token **n2);

/*
** Get the value corresponding to a digit in the base
*/
int	get_value_at_index(struct s_base *base,
			   char *number,
			   int index);

/*
** Change size and "shift" a token so that it does not include zeros
*/
t_rcode	clean_number_str(struct s_base *base,
			 struct s_token *token);

/*
** Compare the value of two numbers
*/
int	my_strcmp_base(struct s_token *,
		       struct s_token *,
		       struct s_base *);

/*
** Allocate a token dynamically and sets its size.
*/
t_rcode	malloc_token_dynamically(struct s_token *token, int size);

#endif
