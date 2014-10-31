/*
** bm_errno.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct 28 08:46:28 2014 brendan rius
** Last update Thu Oct 30 13:32:58 2014 brendan rius
*/

#ifndef BM_ERRNO_H_
# define BM_ERRNO_H_

typedef enum	e_rcode
  {
    OK,
    MISMATCHED_P,
    NOT_ENOUGH_VALUES,
    TOO_MUCH_VALUES,
    COULD_NOT_MALLOC,
    NULL_REFERENCE,
    NOT_IN_BASE,
    WRONG_BASE_LEN,
    DUPLICATE_VALUE_IN_BASE,
    INVALID_CHARACTER,
    EMPTY_BASE
  }		t_rcode;

char	*bm_get_error(t_rcode code);

#endif
