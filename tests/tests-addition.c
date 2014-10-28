/*
** tests-addition.c for Bistromathique in /home/person_l/rendu/Bistromathique/operations
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Oct 28 13:19:31 2014 Louis Person
** Last update Tue Oct 28 13:52:12 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "tokenizer.h"

t_token		*create_nb_token(char *nb)
{
  t_token	*token;

  token = malloc(sizeof(t_token));
  token->type = NUMBER;
  token->string_value = nb;
  token->size = my_strlen(nb);
  return (token);
}

void	test(char *nb1_str, char *nb2_str, char *base, char *expected)
{
  t_token	*nb1;
  t_token	*nb2;
  t_token	*result;

  nb1 = create_nb_token(nb1_str);
  nb2 = create_nb_token(nb2_str);
  result = create_nb_token(NULL);
  bm_add(nb1, nb2, base, result);
  if (!my_strcmp(result->string_value, expected))
  {
    my_putstr("OK\n");
  }
  else
  {
    my_putstr("KO\n");
  }
  free(result);
}

int	main(int ac, char **av)
{
  test("1337", "42", "0123456789", "1379");
  return (0);
}
