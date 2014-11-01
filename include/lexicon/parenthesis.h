/*
** parenthesis.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:53:57 2014 brendan rius
** Last update Mon Oct 27 15:53:57 2014 brendan rius
*/

#ifndef PARENTHESIS_H_
# define PARENTHESIS_H_

struct s_token;

unsigned int	extract_rparenthesis(char *c, struct s_token *token);

unsigned int	extract_lparenthesis(char *c, struct s_token *token);

#endif /* !PARENTHESIS_H_ */
