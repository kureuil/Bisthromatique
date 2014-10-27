/*
** negate.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:53:27 2014 brendan rius
** Last update Mon Oct 27 15:53:28 2014 brendan rius
*/

#ifndef NEGATE_H_
# define NEGATE_H_

struct s_token;

int	action_negate(int n);

unsigned int	extract_negate(char *c, struct s_token *token);

#endif /* !NEGATE_H_ */
