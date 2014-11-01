#ifndef PARSER_H_
# define PARSER_H_

# include "bm_errno.h"

struct s_lexicon;

struct s_base;

struct s_token;

t_rcode		bm_parse_and_eval(struct s_lexicon *lexicon,
				  char *s,
				  struct s_base *base,
				  struct s_token *res);

#endif /* !PARSER_H_ */
