/*
** my_strcapitalize.c for my_strcapitalize in /home/rius_b/rendu/Piscine_C_J06
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Oct  6 11:46:59 2014 brendan rius
** Last update Thu Oct  9 09:39:51 2014 brendan rius
*/

int	is_min(char c)
{
  return (c <= 'z' && c >= 'a');
}

void	capitalize(char *c)
{
  *c = *c - 'a' + 'A';
}

char	*my_strcapitalize(char *str)
{
  char	*ptr_str;
  int	flag;

  ptr_str = str;
  if (!str)
    return (str);
  my_strlowcase(str);
  flag = 1;
  while (*str != '\0')
    {
      if (*str >= '0' && *str <= '9')
	flag = 0;
      else if (is_min(*str) && flag)
	{
	  capitalize(str);
	  flag = 0;
	}
      else if (!is_min(*str))
	flag = 1;
      str++;
    }
  return (ptr_str);
}
