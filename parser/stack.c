/*
** stack.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:25 2014 brendan rius
** Last update Tue Oct 28 14:55:10 2014 brendan rius
*/

#include <stdlib.h>
#include "stack.h"
#include "my.h"
#include "bm_errno.h"

struct s_token;

t_rcode		push(t_stack **top, struct s_token *token)
{
  t_stack	*new;

  if (!top)
    return (NULL_REFERENCE);
  if ((new = malloc(sizeof(t_stack))) == NULL)
    return (COULD_NOT_MALLOC);
  new->data = token;
  if (*top)
    new->next = *top;
  else
    new->next = NULL;
  *top = new;
  return (OK);
}

void		pop(t_stack **top)
{
  t_stack	*tmp;

  if (!top || !*top)
    return;
  tmp = (*top)->next;
  *top = tmp;
}

struct s_token	*top(t_stack *top)
{
  if (!top)
    return (NULL);
  return (top->data);
}
