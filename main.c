/*
** main.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:57:15 2014 brendan rius
** Last update Thu Oct 30 13:34:53 2014 brendan rius
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

void	free_all(t_queue *tokens, t_queue *rpn, t_lexicon *lexicon)
{
  if (rpn)
    free_queue(rpn);
  if (tokens)
    free_queue(tokens);
  if (lexicon)
    free_lexicon(lexicon);
}

int		bm_eval(char *str, t_token **res, t_base *base)
{
  t_queue	*rpn;
  t_queue	*tokens;
  t_lexicon	*lexicon;
  int		ret;

  rpn = NULL;
  tokens = NULL;
  init_queue(&rpn);
  init_queue(&tokens);
  lexicon = get_classic_lexicon();
  if ((ret = bm_get_tokens(lexicon, str, tokens, base)) != OK)
    {
      free_all(tokens, rpn, lexicon);
      return (ret);
    }
  if ((ret = shuntingyard(tokens, rpn)) != OK)
    {
      free_all(tokens, rpn, lexicon);
      return (ret);
    }
  if ((ret = eval_postfix(rpn, res, base)) != OK)
    {
      free_all(tokens, rpn, lexicon);
      return (ret);
    }
  free_all(tokens, rpn, lexicon);
  return (OK);
}

int	bm_exit(char *s)
{
  my_putstr(s);
  return (1);
}

void	display_res(t_token *res)
{
  if (res->sign == NEGATIVE)
    my_putchar('-');
  write(1, res->string_value, res->size);
  my_putchar('\n');
}

int		main(int ac, char **argv)
{
  int		ret;
  int		size;
  int		buflen;
  int		readret;
  t_token	*res;
  t_base	base;
  char		*buffer;

  if (ac < 4)
    return (bm_exit("Wrong number of args\n"));
  new_base(argv[1], &base);
  size = my_getnbr(argv[3]);
  if ((buffer = malloc(size + 1)) == NULL)
    return (bm_exit(bm_get_error(COULD_NOT_MALLOC)));
  buflen = 0;
  while ((readret = read(0, buffer + buflen, size - buflen)) > 0)
    buflen += readret;
  buffer[buflen] = '\0';
  if ((ret = bm_eval(buffer, &res, &base)) != OK)
    return (bm_exit(bm_get_error(ret)));
  display_res(res);
  bm_free_token(res);
  free(buffer);
  return (OK);
}
