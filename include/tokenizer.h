/*
** tokenizer.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:51 2014 brendan rius
** Last update Tue Oct 28 14:21:16 2014 brendan rius
*/

#ifndef TOKENIZER_H_
# define TOKENIZER_H_

# include "bm_errno.h"
# include "operators.h"

struct s_queue;
struct s_lexicon;

/*
** Define the different token types
*/
typedef enum	e_types
  {
    NUMBER,
    LPARENTHESIS,
    RPARENTHESIS,
    OPERATOR,
    U_OPERATOR,
    UNDEFINED
  }		t_ttype;

/*
** Define the two different signs of a token. We assume
** that zero has a positive sign.
*/
typedef enum	e_sign
  {
    POSITIVE,
    NEGATIVE
  }		t_sign;

/*
** A token has a type, a value (which is either an operator structure,
** or a number. A token also contains the its size in the base string.
*/
typedef struct		s_token
{
  t_ttype		type;
  char			*string_value;
  int			size;
  struct s_operator	operator;
  t_sign		sign;
}			t_token;

/*
** Extract all tokens from a string, using a lexicon.
** All the tokens should be correctly defined in the lexicon.
*/
t_rcode	bm_get_tokens(struct s_lexicon *lexicon,
		      char *s,
		      struct s_queue *tokens);

/*
** Free a token. You should always use this function instead of "free()"
*/
int	bm_free_token(t_token *token);

/*
** Create a new empty token
*/
t_rcode	bm_new_token(t_token **token);

#endif /* !TOKENIZER_H_ */
