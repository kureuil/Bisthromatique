##
## Makefile for Makefile in /home/rius_b/rendu/Piscine_C_J11/lib/my
## 
## Made by brendan rius
## Login   <rius_b@epitech.net>
## 
## Started on  Mon Oct 20 08:51:07 2014 brendan rius
## Last update Thu Nov  6 11:41:23 2014 Louis Person
##

CC	= gcc
RM	= rm -f
CP	= cp
CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic

NAME	= libmy

HEADER	= my.h

SRCS	= 	my_char_isalphanum.c \
		my_count_strings.c \
		my_find_prime_sup.c \
		my_getnbr_base.c \
		my_getnbr.c \
		my_go_to_next_string.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_wordtab.c \
		my_sort_int_tab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		my_puterror.c \
		sopalin.c \
		my_memset.c \
		my_char_isdigit.c \
		my_max.c

OBJS	= $(SRCS:.c=.o)

all: link ranlib copylib copyheader clean

compile:
	$(CC) -c $(SRCS)

link: compile
	ar rc $(NAME).a $(OBJS)

ranlib:
	ranlib $(NAME).a

copylib:
	$(CP) $(NAME).a ../$(NAME).a

copyheader:
	$(CP) $(HEADER) ../../include/$(HEADER)

clean:
	$(RM) $(NAME).a $(OBJS)

fclean: clean

re: fclean all
