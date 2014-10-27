/*
** unary_plus.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 17:20:10 2014 brendan rius
** Last update Mon Oct 27 17:23:40 2014 brendan rius
*/

#ifndef UNARY_PLUS_H_
# define UNARY_PLUS_H_

struct s_token;

int	action_unary_plus(int n);

unsigned int	extract_unary_plus(char *, struct s_token *);

#endif /* !UNARY_PLUS_H_ */
