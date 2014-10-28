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

int		extract_from_lexicon(t_lexicon *lexicon,
				     t_queue *queue,
				     char *s)
{
  t_token	*token;

  if (!(token = new_token()))
    return (0);
  while (lexicon != NULL)
    {
      if ((*(lexicon->extract_token))(s, token, rear(queue)))
	{
	  if ((token->string_value = malloc(token->size + 1)) == NULL)
	    return (free_token(token));
	  my_strncpy(token->string_value, s, token->size);
	  token->string_value[token->size] = '\0';
	  enqueue(queue, token);
	  return (token->size);
	}
      lexicon = lexicon->next;
    }
  return (0);
}

t_queue		*get_tokens(t_lexicon *lexicon, char *s)
{
  int		shift;
  t_queue	*queue;

  if (!s)
    return (NULL);
  queue = NULL;
  init_queue(&queue);
  while (*s)
    {
      if (*s != ' ' && *s != '\t')
	shift = extract_from_lexicon(lexicon, queue, s);
      else
	shift = 1;
      s += shift;
    }
  return (queue);
}

int	free_token(t_token *token)
{
  if (!token)
    return (0);
  if (token->string_value)
    free(token->string_value);
  free(token);
  return (0);
}

t_token		*new_token()
{
  t_token	*token;

  if ((token = malloc(sizeof(t_token))) == NULL)
    return (NULL);
  token->string_value = NULL;
  return (token);
}
