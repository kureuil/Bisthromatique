#include <stdlib.h>
#include "tokens.h"
#include "lexicon.h"
#include "bm_base.h"
#include "stack.h"
#include "shuntingyard.h"

t_rcode		bm_extract_from_lexicon(t_lexicon *lexicon,
					t_token **token,
					char **s,
					t_base *base,
					t_token *previous)
{
  while (lexicon != NULL)
    {
      if ((*(lexicon->extract_token))(*s, *token, base, previous))
	{
	  (*token)->string_value = *s;
	  (*token)->dynamic = FALSE;
	  *s += (*token)->size;
	  return (OK);
	}
      lexicon = lexicon->next;
    }
  return (INVALID_CHARACTER);
}

t_rcode		bm_parse_and_eval(t_lexicon *lexicon,
				  char *s,
				  t_base *base,
				  t_token **res)
{
  t_stack	*output;
  t_stack	*op_stack;
  t_token	*token;
  t_rcode	ret;
  t_token	*previous;

  if (!s || !lexicon || !base || !res)
    return (NULL_REFERENCE);
  previous = NULL;
  output = NULL;
  op_stack = NULL;
  while (*s)
    {
      if (!(*s != ' ' && *s != '\t' && *s != '\n'))
	{
	  s++;
	  continue;
	}
      if ((ret = bm_new_token(&token)) != OK)
	return (ret);
      if ((ret = bm_extract_from_lexicon(lexicon, &token, &s, base, previous)) != OK)
	return (ret);
      previous = token;
      bm_shuntingyard(&output, &op_stack, token, base);
    }
  while ((token = top(op_stack)) != NULL)
    {
      if (token->type == LPARENTHESIS || token->type == RPARENTHESIS)
	return (MISMATCHED_P);
      if ((ret = bm_stack_to_output(&output, &op_stack, base)) != OK)
	return (ret);
    }
  *res = top(output);
  return (OK);
}
