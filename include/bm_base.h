/*
** bm_base.h for Bistromathique in /home/rius_b/rendu/Bistromathique/lexicon
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct 28 14:09:46 2014 brendan rius
** Last update Thu Oct 30 13:40:03 2014 brendan rius
*/

#ifndef BM_BASE_H_
# define BM_BASE_H_

# include "bm_errno.h"

# define MAX_BASE_SIZE 255

typedef struct	s_base
{
  char		*string;
  int		array[MAX_BASE_SIZE];
  int		size;
}		t_base;

t_rcode	new_base(char *string, t_base *base);

#endif /* !BM_BASE_H_ */
