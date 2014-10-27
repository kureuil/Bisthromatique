/*
** sopalin.c for sopalin in /home/rius_b/rendu/common/sopalin
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Oct  7 08:47:50 2014 brendan rius
** Last update Fri Oct 24 15:16:06 2014 brendan rius
*/

#define MAX 2147483647
#define MIN -2147483648

int	mult_will_overflow(int n1, int n2)
{
  if (n1 > 0 && n2 > MAX / n1)
    return (1);
  if (n1 < 0 && n2 > 0 && n2 > MIN / n1)
    return (1);
  if (n1 < 0 && n2 < 0 && n2 < MAX / n1)
    return (1);
  if (n1 > 0 && n2 < 0 && n2 < MIN / n1)
    return (1);
  return (0);
}

int	add_will_overflow(int n1, int n2)
{
  if (n1 > 0 && n2 > 0 && n1 > MAX - n2)
    return (1);
  if (n1 < 0 && n2 < 0 && n1 < MIN + n2)
    return (1);
  return (0);
}

int	sub_will_overflow(int n1, int n2)
{
  if (n1 < 0 && n2 > 0 && n1 < MIN + n2)
    return (1);
  if (n1 > 0 && n2 > 0 && n1 > MAX + n2)
    return (1);
  return (0);
}
