#include <stdlib.h>
#include "boolean.h"
#include "tokens.h"

BOOL	bm_token_is_operator(t_token *token)
{
  return (token->type == OPERATOR || token->type == U_OPERATOR);
}

t_rcode	bm_new_token(t_token **token)
{
  if ((*token = malloc(sizeof(t_token))) == NULL)
    return (COULD_NOT_MALLOC);
  (*token)->string_value = NULL;
  (*token)->sign = POSITIVE;
  (*token)->type = UNDEFINED;
  (*token)->size = 0;
  return (OK);
}
