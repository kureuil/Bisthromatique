/*
** main.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:57:15 2014 brendan rius
** Last update Tue Oct 28 17:52:29 2014 brendan rius
*/

#include <unistd.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "shuntingyard.h"
#include "lexicon.h"
#include "queue.h"
#include "my.h"
#include "postfix.h"
#include "bm_errno.h"
#include "bm_base.h"

#define BUFFSIZE 200000

int		eval(char *str, t_token **res, t_base *base)
{
  t_queue	*rpn;
  t_queue	*tokens;
  t_lexicon	*lexicon;
  int		ret;

  rpn = NULL;
  init_queue(&rpn);
  lexicon = get_classic_lexicon();
  tokens = get_tokens(lexicon, str);
  if ((ret = shuntingyard(tokens, rpn)) != OK)
    {
      free_queue(rpn);
      free_queue(tokens);
      free_lexicon(lexicon);
      return (ret);
    }
  if ((ret = eval_postfix(rpn, res, base)) != OK)
    {
      free_queue(rpn);
      free_queue(tokens);
      free_lexicon(lexicon);
      return (ret);
    }
  return (OK);
}

int		main(int ac, char **argv)
{
  t_token	*res;
  int		ret;
  t_base	base;
  int		size;
  char		*buffer;
  int		buflen;
  int		readret;

  if (ac < 4)
    {
      my_puterror("Wrong number of args\n");
      return (1);
    }
  base.size = my_strlen(argv[1]);
  base.string = argv[1];
  size = my_getnbr(argv[3]);
  buffer = malloc(size + 1);
  buflen = 0;
  while ((readret = read(0, buffer + buflen, size - buflen)) > 0)
    buflen += readret;
  buffer[buflen] = '\0';

  if ((ret = eval(buffer, &res, &base)) != OK)
    {
      my_puterror(bm_get_error(ret));
      return (OK);
    }

  my_putstr(res->string_value);
  my_putchar('\n');
  return (OK);
}
