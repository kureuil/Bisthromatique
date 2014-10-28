/*
** main.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:57:15 2014 brendan rius
** Last update Tue Oct 28 13:24:06 2014 brendan rius
*/

#include <stdlib.h>
#include "tokenizer.h"
#include "shuntingyard.h"
#include "lexicon.h"
#include "queue.h"
#include "my.h"
#include "postfix.h"
#include "bm_errno.h"

int		eval(char *str, int *res)
{
  t_queue	*rpn;
  t_queue	*tokens;
  t_lexicon	*lexicon;
  int		ret;

  rpn = new_queue();
  lexicon = get_classic_lexicon();
  tokens = get_tokens(lexicon, str);
  if ((ret = shuntingyard(tokens, rpn)) != OK)
    {
      free_queue(rpn);
      free_queue(tokens);
      free_lexicon(lexicon);
      return (ret);
    }
  *res = eval_postfix(rpn);
  free_queue(rpn);
  free_queue(tokens);
  free_lexicon(lexicon);
  return (OK);
}

int	main(int ac, char **av)
{
  int	res;
  int	ret;

  if (ac > 1)
  {
    if ((ret = eval(av[1], &res)) != OK)
      {
	my_puterror(bm_get_error(ret));
	return (OK);
      }
    my_put_nbr(res);
    my_putchar('\n');
  }
  return (OK);
}
