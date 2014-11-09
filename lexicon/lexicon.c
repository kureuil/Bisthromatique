/*
** lexicon.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:56:54 2014 brendan rius
** Last update Mon Oct 27 17:18:31 2014 brendan rius
*/

#include <stdlib.h>
#include "operators.h"
#include "lexicon.h"
#include "bm_base.h"
#include "my.h"

t_rcode	get_ordered_extractors(t_extract_fct **array)
{
  if ((*array = malloc(sizeof(t_extract_fct) * NB_EXTRACTORS)) == NULL)
    return (COULD_NOT_MALLOC);
  (*array)[0] = &extract_lparenthesis;
  (*array)[1] = &extract_rparenthesis;
  (*array)[2] = &extract_add;
  (*array)[3] = &extract_sub;
  (*array)[4] = &extract_mul;
  (*array)[5] = &extract_div;
  (*array)[6] = &extract_mod;
  return (OK);
}

void	init_extractors(t_lexicon *lexicon)
{
  int	i;

  i = 0;
  while (i < MAX_EXTRACTORS)
    {
      lexicon->extractors[i] = NULL;
      ++i;
    }
}

void	add_numbers_to_extractors(t_lexicon *lexicon,
				  t_base *base)
{
  int	i;

  i = 0;
  while (i < MAX_EXTRACTORS)
    {
      if (base->array[i] != -1)
	lexicon->extractors[i] = &extract_number;
      ++i;
    }
}

t_rcode	add_ops_to_extractors(t_lexicon *lexicon,
			      char *operators,
			      t_extract_fct *ordered_fcts,
			      int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      if (lexicon->extractors[(unsigned char) operators[i]] != NULL)
	return (DUPLICATE_VALUE_IN_OPERATORS_OR_BASE);
      lexicon->extractors[(unsigned char) operators[i]] = ordered_fcts[i];
      ++i;
    }
  free(ordered_fcts);
  return (OK);
}

t_rcode		get_classic_lexicon(t_lexicon *lexicon,
				    char *ops,
				    t_base *base)
{
  int		len;
  t_rcode	ret;
  t_extract_fct	*ordered_fcts;

  if (!lexicon)
    return (NULL_REFERENCE);
  if ((ret = get_ordered_extractors(&ordered_fcts)) != OK)
    return (ret);
  len = my_strlen(ops);
  if (len == 0)
    return (EMPTY_OPERATORS);
  if (len != 7)
    return (WRONG_OPS_LEN);
  init_extractors(lexicon);
  add_numbers_to_extractors(lexicon, base);
  if ((ret = add_ops_to_extractors(lexicon, ops, ordered_fcts, len)) != OK)
    return (ret);
  return (OK);
}
