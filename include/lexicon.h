/*
** lexicon.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:52:05 2014 brendan rius
** Last update Mon Oct 27 16:11:12 2014 brendan rius
*/

#ifndef LEXICON_H_
# define LEXICON_H_

# include "bm_errno.h"

# define MAX_EXTRACTORS 256

# define NB_EXTRACTORS 7

struct s_token;

struct s_base;

typedef t_rcode (*t_extract_fct)();

/*
** Note: cannot handle string that contains more than 2^(32) chars.
** The function "extract_token" returns the length of the extracted token
** (0 if any) and fills it.
*/
typedef struct		s_lexicon
{
  t_extract_fct		extractors[MAX_EXTRACTORS];
}			t_lexicon;

t_rcode	get_classic_lexicon(t_lexicon *lexicon,
			    char *operators,
			    struct s_base *base);

#endif /* !LEXICON_H_ */
