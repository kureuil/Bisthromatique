/*
** my.h for my in /home/rius_b/rendu/Piscine_C_J08/ex_04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct 10 11:18:26 2014 brendan rius
** Last update Mon Nov  3 09:37:04 2014 Louis Person
*/

#ifndef MY_H_
# define MY_H_

int	my_find_prime_sup(int nb);
int	my_getnbr_base(char *str, char *base);
int	my_getnbr(char *str);
long	my_getlnbr(char *str);
int	my_isneg(int n);
int	my_is_prime(int nb);
int	my_power_rec(int nb, int power);
int	my_putchar(char c);
int	my_putnbr_base(int nbr, char *base);
int	my_put_nbr(int n);
int	my_putstr(char *str);
void	my_puterror(char *str);
char	*my_revstr(char *str);
int	my_showmem(char *str, int size);
int	my_showstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);
int	my_swap(int *a, int *b);
int	mult_will_overflow(int n1, int n2);
int	add_will_overflow(int n1, int n2);
int	sub_will_overflow(int n1, int n2);
short	my_char_isalphanum(char c);
char	*go_to_next_string(char *str, short fct(char));
int	my_count_strings(char *str, short fct(char));
char	**my_str_to_wordtab(char *str);
char	*my_strdup(char *str);
void	*my_memset(void *s, char c, int n);
char	my_char_isdigit(char c);

#endif /* !MY_H_ */
