/*
** my_count_strings.c for my_count_strings in /home/rius_b/rendu/Piscine_C_J08/ex_04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct 10 11:06:50 2014 brendan rius
** Last update Fri Oct 10 11:08:26 2014 brendan rius
*/

/*
** Count the number of strings whose chars match the return of the function.
** The string should be NUL-terminated.
*/
int	my_count_strings(char *str, short fct(char))
{
  int	nb_words;
  short	hesc;

  hesc = 1;
  nb_words = 0;
  while (*str)
    {
      if (!fct(*str))
	hesc = 1;
      else
	{
	  if (hesc)
	    {
	      ++nb_words;
	      hesc = 0;
	    }
	}
      ++str;
    }
  return (nb_words);
}
