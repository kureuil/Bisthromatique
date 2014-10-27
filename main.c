/*
** main.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:57:15 2014 brendan rius
** Last update Mon Oct 27 16:22:12 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "shuntingyard.h"
#include "lexicon.h"
#include "queue.h"
#include "my.h"
#include "postfix.h"

int		eval(char *str)
{
  t_queue	*rpn;
  t_queue	*tokens;
  t_lexicon	*lexicon;
  int		nb;

  lexicon = get_classic_lexicon();
  tokens = get_tokens(lexicon, str);
  rpn = shuntingyard(tokens);
  nb = eval_postfix(rpn);
  free_queue(rpn);
  free_queue(tokens);
  free_lexicon(lexicon);
  return (nb);
}

int	main(int ac, char **av)
{
  if (ac > 1)
  {
    my_put_nbr(eval(av[1]));
    my_putchar('\n');
  }
  return (0);
}
