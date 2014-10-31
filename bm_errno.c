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
  if (code == MISMATCHED_P)
    return ("mismatched parenthesis\n");
  else if (code == TOO_MUCH_VALUES)
    return ("too much values\n");
  else if (code == NOT_ENOUGH_VALUES)
    return ("not enough values\n");
  else if (code == COULD_NOT_MALLOC)
    return ("could not malloc\n");
  else if (code == NULL_REFERENCE)
    return ("null reference\n");
  else if (code == NOT_IN_BASE)
    return ("character not in base\n");
  else if (code == WRONG_BASE_LEN)
    return ("the base has an invalid length\n");
  else if (code == DUPLICATE_VALUE_IN_BASE)
    return ("the base contains duplicate characters\n");
  else if (code == INVALID_CHARACTER)
    return ("invalid character in string\n");
  else if (code == EMPTY_BASE)
    return ("empty base\n");
  else
    return ("unknown error\n");
}
