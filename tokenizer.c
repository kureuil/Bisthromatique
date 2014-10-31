/*
** tokenizer.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:00:30 2014 brendan rius
** Last update Tue Oct 28 16:11:03 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "lexicon.h"
#include "queue.h"
#include "my.h"

t_rcode		bm_extract_from_lexicon(t_lexicon *lexicon,
					t_queue *queue,
					char *s,
					int *shift)
{
  t_token	*token;
  t_rcode	ret;

  token = NULL;
  if ((ret = bm_new_token(&token)) != OK)
    return (ret);
  while (lexicon != NULL)
    {
      if ((*(lexicon->extract_token))(s, token, rear(queue)))
	{
	  token->string_value = s;
	  enqueue(queue, token);
	  *shift = token->size;
	  return (OK);
	}
      lexicon = lexicon->next;
    }
  *shift = 0;
  return (OK);
}

t_rcode		bm_get_tokens(t_lexicon *lexicon, char *s, t_queue *tokens)
{
  int		shift;
  t_rcode	ret;

  if (!s || !tokens)
    return (NULL_REFERENCE);
  while (*s)
    {
      if (*s != ' ' && *s != '\t')
	{
	  if ((ret = bm_extract_from_lexicon(lexicon, tokens, s, &shift)) != OK)
	    return (ret);
	}
      else
	shift = 1;
      s += shift;
    }
  return (OK);
}

int	bm_free_token(t_token *token)
{
  if (!token)
    return (0);
  free(token);
  return (0);
}

t_rcode	bm_new_token(t_token **token)
{
  if ((*token = malloc(sizeof(t_token))) == NULL)
    return (COULD_NOT_MALLOC);
  (*token)->string_value = NULL;
  (*token)->sign = POSITIVE;
  (*token)->type = UNDEFINED;
  (*token)->size = 0;
  return (OK);
}
