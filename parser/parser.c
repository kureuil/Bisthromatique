/*
** parser.c for Bistromathique in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Nov  2 14:00:57 2014 Louis Person
** Last update Sun Nov  2 14:09:46 2014 Louis Person
*/

#include <stdlib.h>
#include "tokens.h"
#include "lexicon.h"
#include "bm_base.h"
#include "stack.h"
#include "shuntingyard.h"
#include "parser.h"

t_rcode		bm_extract_from_lexicon(t_lexicon *lexicon,
					char **s,
					t_base *base,
					t_token_cursor *crsr)
{
  t_rcode	ret;
  t_extract_fct	fct;

  fct = lexicon->extractors[(unsigned char) **s];
  if (fct == NULL)
    return (INVALID_CHARACTER);
  ret = (*fct)(*s, crsr->actual, base, crsr->previous);
  if (ret == OK)
    {
      crsr->actual->string_value = *s;
      crsr->actual->dynamic = FALSE;
      *s += crsr->actual->size;
      return (OK);
    }
  else
    return (ret);
}

t_rcode		pop_last_ops(t_token_cursor *cursors,
			     t_base *base,
			     t_stack **output,
			     t_stack **op_stack)
{
  t_rcode	ret;

  while ((cursors->actual = top(*op_stack)) != NULL)
    {
      if (bm_token_is_parenthesis(cursors->actual))
	return (MISMATCHED_P);
      if ((ret = bm_stack_to_output(output, op_stack, base)) != OK)
	return (ret);
    }
  return (OK);
}

t_rcode	set_res(t_token	**res, t_stack **output, t_stack **op_stack)
{
  if ((*res = top(*output)) == NULL)
    return (NOT_ENOUGH_VALUES);
  pop(output);
  if (top(*output) != NULL)
    {
      free(*output);
      free(*op_stack);
      return (TOO_MUCH_VALUES);
    }
  free(*output);
  free(*op_stack);
  return (OK);
}

t_rcode			bm_parse_and_eval(t_lexicon *lexicon,
					  char *s,
					  t_base *base,
					  t_token **res)
{
  t_stack		*output;
  t_stack		*ops;
  t_rcode		ret;
  t_token_cursor	crsrs;

  if (!s || !lexicon || !base || !res)
    return (NULL_REFERENCE);
  crsrs.previous = crsrs.actual = NULL;
  output = ops = NULL;
  while (*s)
    {
      if ((ret = bm_new_token(&(crsrs.actual))) != OK ||
	  (ret = bm_extract_from_lexicon(lexicon, &s, base, &crsrs)) != OK)
	return (ret);
      crsrs.previous = crsrs.actual;
      if ((ret = bm_shuntingyard(&output, &ops, crsrs.actual, base)) != OK)
	return (ret);
    }
  if (!crsrs.previous)
    return (NOTHING_TO_READ);
  if ((ret = pop_last_ops(&crsrs, base, &output, &ops)) != OK)
    return (ret);
  return (set_res(res, &output, &ops));
}
