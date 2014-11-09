/*
** bm_errno.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct 28 08:47:48 2014 brendan rius
** Last update Tue Oct 28 13:48:43 2014 brendan rius
*/

#include "bm_errno.h"
#include "my.h"

char	*bm_get_error(t_rcode code)
{
  char	*errors[NB_ERRORS];

  errors[MISMATCHED_P] = "syntax error";
  errors[NOT_ENOUGH_VALUES] = "syntax error";
  errors[TOO_MUCH_VALUES] = "syntax error";
  errors[COULD_NOT_MALLOC] = "could not alloc\n";
  errors[NULL_REFERENCE] = "null reference\n";
  errors[NOT_IN_BASE] = "syntax error";
  errors[WRONG_BASE_LEN] = "Bad base\n";
  errors[DUPLICATE_VALUE_IN_BASE] = "the base contains duplicate characters\n";
  errors[INVALID_CHARACTER] = "syntax error";
  errors[EMPTY_BASE] = "empty base\n";
  errors[READ_ERROR] = "could not read\n";
  errors[NOTHING_TO_READ] = "Bad expr len\n";
  errors[WRITE_FAILED] = "write failed\n";
  errors[WRONG_NB_ARGS] = "wrong number of args\n";
  errors[DUPLICATE_VALUE_IN_OPERATORS_OR_BASE] = "Bad ops\n";
  errors[EMPTY_OPERATORS] = "Bad ops\n";
  errors[WRONG_OPS_LEN] = "Bad base\n";
  errors[DIVISION_BY_ZERO] = "division by zero\n";
  errors[MODULO_BY_ZERO] = "modulo by zero\n";
  if (code < NB_ERRORS)
    return errors[code];
  else
    return ("unknown error\n");
}

int	usage(char *cmd)
{
  my_putstr("Usage : ");
  my_putstr(cmd);
  my_putstr(" base ops\"()+-*/%\" exp_len\n");
  return (1);
}
