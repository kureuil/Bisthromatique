/*
** my_getnbr.c for my_getnbr in /home/rius_b/rendu/Piscine_C_J04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  2 08:58:43 2014 brendan rius
** Last update Sun Oct 26 23:39:05 2014 brendan rius
*/

#include "my.h"

int	my_getnbr(char *s)
{
  return (my_getnbr_base(s, "0123456789"));
}
