/*
** my_putstr.c for my_putstr in /home/rius_b/rendu/Piscine_C_J04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Oct  2 08:46:37 2014 brendan rius
** Last update Sat Oct 25 08:38:03 2014 brendan rius
*/

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
