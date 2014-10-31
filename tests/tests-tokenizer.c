/*
** tests-tokenizer.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:12:49 2014 brendan rius
** Last update Mon Oct 27 16:46:05 2014 brendan rius
*/

#include <stdlib.h>
#include "my.h"
#include "queue.h"
#include "tokenizer.h"
#include "lexicon.h"

void	display_type(t_token *token)
{
  if (token->type == OPERATOR)
    my_putstr("binary");
  else if (token->type == U_OPERATOR)
    my_putstr("unary");
  else if (token->type == NUMBER)
    my_putstr("number");
  else if (token->type == LPARENTHESIS)
    my_putstr("left p");
  else if (token->type == RPARENTHESIS)
    my_putstr("right p");
}

int		main(int argc, char **argv)
{
  t_token	*token;
  t_queue	*tokens;
  t_lexicon	*lexicon;

  if (argc < 2)
    {
      my_puterror("Wrong number of args\n");
      return (0);
    }
  tokens = NULL;
  lexicon = get_classic_lexicon();
  bm_get_tokens(lexicon, argv[1], tokens);
  while ((token = (t_token *) front(tokens)))
    {
      dequeue(tokens);
      display_type(token);
      my_putstr("\t\t");
      my_putstr(token->string_value);
      my_putchar('\n');
      bm_free_token(token);
    }
  free_queue(tokens);
  free_lexicon(lexicon);
  return (0);
}
