/*
** tests-shyard.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 16:05:02 2014 brendan rius
** Last update Tue Oct 28 13:24:35 2014 brendan rius
*/

#include <stdlib.h>
#include "my.h"
#include "lexicon.h"
#include "shuntingyard.h"
#include "postfix.h"
#include "tokenizer.h"
#include "bm_errno.h"

int	main(int argc, char **argv)
{
  t_queue	*tokens;
  t_queue	*rpn;
  t_lexicon	*lexicon;
  int		ret;

  if (argc < 2)
    {
      my_puterror("Wrong number of args\n");
      return (0);
    }
  tokens = NULL;
  rpn = NULL;
  lexicon = get_classic_lexicon();
  bm_get_tokens(lexicon, argv[1], tokens);
  if ((ret = shuntingyard(tokens, rpn)) != OK)
    {
      my_puterror(bm_get_error(ret));
      return (0);
    }
  display_rpn(rpn);
  my_putchar('\n');
  free_queue(tokens);
  free_lexicon(lexicon);
  return (0);
}
