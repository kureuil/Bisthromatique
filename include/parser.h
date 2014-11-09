/*
** parser.h for Bistromathique in /home/brendan/rendu/Bistromathique
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Nov  3 01:15:44 2014 Brendan Rius
** Last update Mon Nov  3 01:15:44 2014 Brendan Rius
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "bm_errno.h"

struct s_lexicon;

struct s_base;

struct s_token;

typedef struct		s_token_cursor
{
  struct s_token	*actual;
  struct s_token	*previous;
}			t_token_cursor;

t_rcode	bm_parse_and_eval(struct s_lexicon *lexicon,
			  char *s,
			  struct s_base *base,
			  struct s_token **res);

#endif /* !PARSER_H_ */
