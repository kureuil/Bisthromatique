/*
** tokens.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:54:51 2014 brendan rius
** Last update Tue Oct 28 14:21:16 2014 brendan rius
*/

#ifndef TOKENS_H_
# define TOKENS_H_

# include "bm_errno.h"
# include "operators.h"
# include "boolean.h"

struct s_queue;

struct s_lexicon;

struct s_base;

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
** A token has a type, a value (string), a size, a sign if it is a number,
** an operator structure if it is an operator, an pointer to the address to free
** (used to improve perfs). The dynamic flag is set to true if the value has
** been dynamically allocated, so we won't free what the GC will
*/
typedef struct		s_token
{
  t_ttype		type;
  BOOL			dynamic;
  char			*real_address;
  char			*string_value;
  int			size;
  struct s_operator	operator;
  t_sign		sign;
}			t_token;

/*
** Free a token. You should always use this function instead of "free()"
*/
t_rcode	bm_free_token(t_token *token);

/*
** Create a new empty token
*/
t_rcode	bm_new_token(t_token **token);

/*
** Returns true if the token is an operator (binary or unary), false
** otherwise.
*/
BOOL	bm_token_is_operator(t_token *token);

#endif /* !TOKENS_H_ */
