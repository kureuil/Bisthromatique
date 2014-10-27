/*
** tests-shyard.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:05:02 2014 brendan rius
** Last update Mon Oct 27 16:43:08 2014 brendan rius
*/

#include "my.h"
#include "lexicon.h"
#include "shuntingyard.h"
#include "postfix.h"
#include "tokenizer.h"

int	main(int argc, char **argv)
{
  t_queue	*tokens;
  t_lexicon	*lexicon;

  if (argc < 2)
    {
      my_puterror("Wrong number of args\n");
      return (0);
    }
  lexicon = get_classic_lexicon();
  tokens = get_tokens(lexicon, argv[1]);
  display_rpn(shuntingyard(tokens));
  my_putchar('\n');
  free_queue(tokens);
  free_lexicon(lexicon);
  return (0);
}
