/*
** number.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:53:36 2014 brendan rius
** Last update Mon Oct 27 15:53:37 2014 brendan rius
*/

#ifndef NUMBER_H_
# define NUMBER_H_

# include "bm_errno.h"

struct s_token;

struct s_base;

t_rcode	extract_number(char *,
		       struct s_token *,
		       struct s_base *);

#endif /* !NUMBER_H_ */
