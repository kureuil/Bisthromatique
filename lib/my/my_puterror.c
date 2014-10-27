/*
** my_puterror.c for my_puterror in /home/rius_b/rendu/Piscine_C_J13
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Oct 22 10:40:52 2014 brendan rius
** Last update Wed Oct 22 10:55:40 2014 brendan rius
*/

void	my_puterror(char *str)
{
  if (!str)
    return;
  while (*str)
    {
      write(2, str, 1);
      ++str;
    }
}
