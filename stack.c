/*
** stack.c for Bistromathique in /home/rius_b/rendu/Bistromathique
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct 27 15:59:25 2014 brendan rius
** Last update Mon Oct 27 15:59:25 2014 brendan rius
*/

#include <stdlib.h>
#include "stack.h"
#include "my.h"

void		push(t_stack **top, void *data)
{
  t_stack	*new;

  if (!top)
    {
      my_puterror("Wrong stack pointer. Aborted.\n");
      return;
    }
  if ((new = malloc(sizeof(t_stack))) == NULL)
    {
      my_puterror("Malloc failed. Aborted.\n");
      return;
    }
  new->data = data;
  if (*top)
    new->next = *top;
  else
    new->next = NULL;
  *top = new;
}

void		pop(t_stack **top)
{
  t_stack	*tmp;

  if (!top || !*top)
    return;
  tmp = (*top)->next;
  free(*top);
  *top = tmp;
}

void	*top(t_stack *top)
{
  if (!top)
    return (NULL);
  return (top->data);
}

void		free_stack(t_stack **top)
{
  if (!top)
    return;
  while (*top)
    {
      pop(top);
    }
  free(*top);
}
