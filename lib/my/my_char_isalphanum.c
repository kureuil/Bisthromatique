/*
** my_char_isalphanum.c for my_char_isalphanum in /home/rius_b/rendu/Piscine_C_J08/ex_04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct 10 11:00:02 2014 brendan rius
** Last update Tue Oct 21 15:53:26 2014 brendan rius
*/

short	my_char_isalphanum(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
