/*
** lexicon.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:54 2014 brendan rius
** Last update Mon Oct 27 16:12:13 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "operators.h"

void	add(t_lexicon **head,
	    unsigned int (*extract)())
{
  t_lexicon	*lexicon;
  t_lexicon	*copy;

  if (!head)
    return;
  if ((lexicon = malloc(sizeof(t_lexicon))) == NULL)
    return;
  copy = *head;
  lexicon->extract_token = extract;
  lexicon->next = NULL;
  if (!*head)
    {
      *head = lexicon;
      return;
    }
  while (copy)
    {
      if (copy->next == NULL)
	{
	  copy->next = lexicon;
	  return;
	}
      copy = copy->next;
    }
}

void		free_lexicon(t_lexicon *lexicon)
{
  t_lexicon	*next;

  while (lexicon)
    {
      next = lexicon->next;
      free(lexicon);
      lexicon = next;
    }
}

t_lexicon	*get_classic_lexicon()
{
  t_lexicon	*lexicon;

  lexicon = NULL;
  add(&lexicon, &extract_lparenthesis);
  add(&lexicon, &extract_rparenthesis);
  add(&lexicon, &extract_number);
  add(&lexicon, &extract_mod);
  add(&lexicon, &extract_mul);
  add(&lexicon, &extract_add);
  add(&lexicon, &extract_div);
  add(&lexicon, &extract_sub);
  add(&lexicon, &extract_negate);
  return (lexicon);
}
