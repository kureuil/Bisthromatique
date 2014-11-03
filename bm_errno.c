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

char	*bm_get_error(t_rcode code)
{
  char	*errors[NB_ERRORS];

  errors[OK] = "internal error\n";
  errors[MISMATCHED_P] = "mismatched parenthesis\n";
  errors[NOT_ENOUGH_VALUES] = "not enough values\n";
  errors[TOO_MUCH_VALUES] = "too much values\n";
  errors[COULD_NOT_MALLOC] = "could not malloc\n";
  errors[NULL_REFERENCE] = "null reference\n";
  errors[NOT_IN_BASE] = "character not in base\n";
  errors[WRONG_BASE_LEN] = "the base has an invalid length\n";
  errors[DUPLICATE_VALUE_IN_BASE] = "the base contains duplicate characters\n";
  errors[INVALID_CHARACTER] = "invalid character in string\n";
  errors[EMPTY_BASE] = "empty base\n";
  errors[READ_ERROR] = "read error\n";
  errors[NOTHING_TO_READ] = "nothing to read\n";
  errors[WRITE_FAILED] = "write failed\n";
  errors[WRONG_NB_ARGS] = "wrong number of args\n";
  if (code < NB_ERRORS)
    return errors[code];
  else
    return ("unknown error\n");
}
