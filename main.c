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
#include "tokens.h"
#include "lexicon.h"
#include "parser.h"
#include "my.h"
#include "bm_errno.h"
#include "bm_base.h"
#include "main.h"

int		bm_eval(char *str, t_token **res, t_base *base)
{
  t_lexicon	*lexicon;
  t_rcode	ret;

  lexicon = get_classic_lexicon();
  if ((ret = bm_parse_and_eval(lexicon, str, base, res)) != OK)
    {
      free_lexicon(lexicon);
      return (ret);
    }
  free_lexicon(lexicon);
  return (OK);
}

int	bm_exit(char *s)
{
  my_puterror("error: ");
  my_puterror(s);
  return (1);
}

int	display_res(t_token *res, t_base *base)
{
  if (res->sign == NEGATIVE &&
      !(res->size == 1 && res->string_value[0] == base->string[0]))
    my_putchar('-');
  if (write(STDOUT, res->string_value, res->size) == -1)
    bm_exit(bm_get_error(WRITE_FAILED));
  my_putchar('\n');
  bm_free_token(res);
  return (0);
}

t_rcode	read_stdin_to_buffer(char *buffer,
			     unsigned int size)
{
  int	readret;
  int	buflen;

  buflen = 0;
  while ((readret = read(STDIN, buffer + buflen, size - buflen)) > 0)
    buflen += readret;
  if (readret == -1)
    return (READ_ERROR);
  if (buflen == 0)
    return (NOTHING_TO_READ);
  buffer[buflen] = '\0';
  return (OK);
}

int		main(int argc, char **argv)
{
  int		size;
  char		*buffer;
  t_token	*res;
  t_base	base;
  t_rcode	ret;

  if (argc < 4)
    return (bm_exit(bm_get_error(WRONG_NB_ARGS)));
  if ((ret = new_base(argv[1], &base)) != OK)
    return (bm_exit(bm_get_error(ret)));
  size = my_getnbr(argv[3]);
  if ((buffer = malloc(size + 1)) == NULL)
    return (bm_exit(bm_get_error(COULD_NOT_MALLOC)));
  if ((ret = read_stdin_to_buffer(buffer, size)) != OK)
    {
      free(buffer);
      return (bm_exit(bm_get_error(ret)));
    }
  if ((ret = bm_eval(buffer, &res, &base)) != OK)
    {
      free(buffer);
      return (bm_exit(bm_get_error(ret)));
    }
  display_res(res, &base);
  free(buffer);
  return (0);
}
