##
## Makefile for Bistromathique in /home/rius_b/rendu/Bistromathique
## 
## Made by brendan rius
## Login   <rius_b@epitech.net>
## 
## Started on  Mon Oct 27 15:58:06 2014 brendan rius
## Last update Sun Nov  9 22:58:02 2014 Louis Person
##

CC	= gcc
RM	= rm -f
CP	= cp
CFLAGS	+= -Wextra -Wall -Werror -Wno-unused-parameter
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I ./include/ -L ./lib/ -l my
LDFLAGS += -I ./include/ -L ./lib/ -l my

# [MODULE] Sources of operations
OP_SRCS	= lexicon/add.c \
	lexicon/mul.c \
	lexicon/div.c \
	lexicon/mod.c \
	lexicon/sub.c \
	lexicon/parenthesis.c \
	lexicon/number.c \
	lexicon/utils.c \
	lexicon/karatsuba_utils.c \
	lexicon/karatsuba_split.c

# [MODULE] Sources needed to use lexicon
SRCS_LEXICON	= lexicon/lexicon.c
SRCS_LEXICON	+= $(OP_SRCS)

# [MODULE] Sources needed to user parser
SRCS_PARSER	= parser/parser.c \
		parser/shuntingyard.c \
		parser/tokens.c \
		parser/stack.c \
		parser/postfix.c
SRCS_PARSER	+= $(SRCS_LEXICON)

# MAIN EXECUTABLE
NAME	= calc
SRCS	= main.c \
	bm_errno.c \
	bm_base.c
SRCS	+= $(SRCS_PARSER)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

test: $(NAME)
	./test/gen.py 10
	./test/engine.sh
	$(RM) ./test/testscases/*

re: fclean all
