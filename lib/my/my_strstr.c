/*
** my_strstr.c for my_strstr in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 09:02:05 2014 brendan rius
** Last update Thu Oct  9 09:39:49 2014 brendan rius
*/

char	*my_strstr(char *str, char *to_find)
{
  int	index_in_str;
  int	copy_index;
  int	i;

  if (!str || !to_find)
    return (!str ? str : to_find);
  if (*to_find == '\0')
    return (str);
  if (*str == '\0')
    return ((void*) 0);
  index_in_str = 0;
  while (str[index_in_str] != '\0')
    {
      copy_index = index_in_str;
      i = 0;
      while (str[copy_index++] == to_find[i++])
	{
	  if (to_find[i] == '\0')
	    return (str + index_in_str);
	}
      ++index_in_str;
    }
  return ((void*) 0);
}
