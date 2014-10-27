/*
** operators.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:53:44 2014 brendan rius
** Last update Mon Oct 27 17:22:10 2014 brendan rius
*/

#ifndef OPERATORS_H_
# define OPERATORS_H_

# include "add.h"
# include "sub.h"
# include "mul.h"
# include "div.h"
# include "mod.h"
# include "negate.h"
# include "parenthesis.h"
# include "number.h"
# include "unary_plus.h"

/*
** Define an operator: it has a precedence (between
** 0 and 255, 0 being the most precedent) and a function
** that computes an integer result from two integers.
*/
typedef struct	s_operator
{
  char		precedence;
  int		(*action)();
}		t_operator;

#endif /* !OPERATORS_H_ */
