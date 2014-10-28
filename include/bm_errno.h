/*
** bm_errno.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct 28 08:46:28 2014 brendan rius
** Last update Tue Oct 28 17:00:00 2014 brendan rius
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
    NOT_IN_BASE
  }		t_rcode;

char	*bm_get_error(t_rcode code);

#endif
