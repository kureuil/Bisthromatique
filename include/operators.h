/*
** operators.h for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:53:44 2014 brendan rius
** Last update Tue Oct 28 14:06:05 2014 brendan rius
*/

#ifndef OPERATORS_H_
# define OPERATORS_H_

# include "bm_errno.h"
# include "lexicon/add.h"
# include "lexicon/sub.h"
# include "lexicon/mul.h"
# include "lexicon/div.h"
# include "lexicon/mod.h"
# include "lexicon/negate.h"
# include "lexicon/parenthesis.h"
# include "lexicon/number.h"
# include "lexicon/unary_plus.h"

/*
** Define an operator: it has a precedence (between
** 0 and 255, 0 being the most precedent) and a function
** that computes an integer result from two integers.
*/
typedef struct	s_operator
{
  char		precedence;
  t_rcode	(*action)();
}		t_operator;

#endif /* !OPERATORS_H_ */
