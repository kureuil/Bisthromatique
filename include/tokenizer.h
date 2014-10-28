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

# include "operators.h"
# include "lexicon.h"
# include "queue.h"

/*
** Define the different token types
*/
typedef enum	e_types
  {
    NUMBER,
    LPARENTHESIS,
    RPARENTHESIS,
    OPERATOR,
    U_OPERATOR
  }		t_ttype;

typedef enum	e_sign
  {
    POSITIVE,
    NEGATIVE
  }		t_sign;

/*
** A token has a type, a value (which is either an operator structure,
** or a number. A token also contains the its size in the base string.
*/
typedef struct	s_token
{
  t_ttype	type;
  char		*string_value;
  int		size;
  t_operator	operator;
  t_sign	sign;
}		t_token;

/*
** Get the first token of a string and returns it.
** Return NULL in case of error.
** All the tokens should be correctly defined in the lexicon.
*/
t_queue	*get_tokens(t_lexicon *lexicon, char *s);

/*
** Free a token. You should always use this function instead of "free()"
*/
int	free_token(t_token *token);

/*
** Create a new empty token
*/
t_token	*new_token();

#endif /* !TOKENIZER_H_ */
