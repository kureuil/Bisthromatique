/*
** tokens.c for Bistromathique in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Nov  2 14:39:32 2014 Louis Person
** Last update Sun Nov  2 14:39:33 2014 Louis Person
*/

#include <unistd.h>
#include <stdlib.h>
#include "boolean.h"
#include "tokens.h"
#include "my.h"

BOOL	bm_token_is_parenthesis(t_token *token)
{
  return (token->type == LPARENTHESIS || token->type == RPARENTHESIS);
}

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
  (*token)->dynamic = TRUE;
  (*token)->size = 0;
  return (OK);
}

t_rcode	bm_free_token(t_token *token)
{
  if (!token)
    return (NULL_REFERENCE);
  if (token->dynamic && token->real_address)
    free(token->real_address);
  free(token);
  return (OK);
}

void	bm_print_token(t_token *token)
{
  my_putstr("----- TOKEN -----\n");
  my_putstr("size:\t");
  my_put_nbr(token->size);
  my_putstr("\nvalue:\t");
  write(1, token->string_value, token->size);
  my_putstr("\n------ END -------\n");
}
