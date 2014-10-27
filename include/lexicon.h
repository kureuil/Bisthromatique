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

struct s_token;

/*
** Note: cannot handle string that contains more than 2^(32) chars.
** The function "extract_token" returns the length of the extracted token
** (0 if any) and fills it.
*/
typedef struct		s_lexicon
{
  unsigned int		(*extract_token)();
  struct s_lexicon	*next;
}			t_lexicon;

void	add(t_lexicon **, unsigned int (*)());

void	free_lexicon(t_lexicon *lexicon);

t_lexicon	*get_classic_lexicon();

#endif /* !LEXICON_H_ */
