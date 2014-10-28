##
## Makefile for Bistromathique in /home/rius_b/rendu/Bistromathique
## 
## Made by brendan rius
## Login   <rius_b@epitech.net>
## 
## Started on  Mon Oct 27 15:58:06 2014 brendan rius
## Last update Tue Oct 28 17:58:21 2014 brendan rius
##

CC	= gcc
RM	= rm -f
CP	= cp
CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -g -I ./include/ -L ./lib/ -l my
LDFLAGS += -g -I ./include/ -L ./lib/ -l my

SRCS_QUEUE	= queue/queue.c \
		queue/queue_operations.c

OP_SRCS	= lexicon/add.c \
	lexicon/mul.c \
	lexicon/div.c \
	lexicon/mod.c \
	lexicon/sub.c \
	lexicon/parenthesis.c \
	lexicon/number.c \
	lexicon/negate.c \
	lexicon/unary_plus.c

NAME	= calc
SRCS	= main.c \
	lexicon.c \
	stack.c \
	tokenizer.c \
	shuntingyard.c \
	postfix.c \
	bm_errno.c
SRCS	+= $(SRCS_QUEUE)
SRCS	+= $(OP_SRCS)

OBJS	= $(SRCS:.c=.o)

# Sources, objects and name for queue
D_SRCS_QUEUE	= tests/tests-queue.c \
		tokenizer.c
D_SRCS_QUEUE	+= $(SRCS_QUEUE)
D_OBJS_QUEUE	= $(D_SRCS_QUEUE:.c=.o)
D_NAME_QUEUE	= tests-queue

# Sources, objects and name for stack
D_SRCS_STACK	= stack.c \
		tokenizer.c \
		tests/tests-stack.c
D_OBJS_STACK	= $(D_SRCS_STACK:.c=.o)
D_NAME_STACK	= tests-stack

# Sources, objects and name for token
D_SRCS_TOKEN	= tokenizer.c \
		tests/tests-tokenizer.c \
		lexicon.c
D_SRCS_TOKEN	+= $(SRCS_QUEUE)
D_SRCS_TOKEN	+= $(OP_SRCS)
D_OBJS_TOKEN	= $(D_SRCS_TOKEN:.c=.o)
D_NAME_TOKEN	= tests-tokenizer

# Sources, objects and name for shunting yard
D_SRCS_SHYARD	= shuntingyard.c \
		stack.c \
		tokenizer.c \
		lexicon.c \
		postfix.c \
		bm_errno.c \
		tests/tests-shyard.c
D_SRCS_SHYARD	+= $(SRCS_QUEUE)
D_SRCS_SHYARD	+= $(OP_SRCS)
D_OBJS_SHYARD	= $(D_SRCS_SHYARD:.c=.o)
D_NAME_SHYARD	= tests-shyard

all: $(NAME) tests

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

tests-queue: $(D_OBJS_QUEUE)
	$(CC) -o $(D_NAME_QUEUE) $(D_OBJS_QUEUE) $(LDFLAGS)

tests-stack: $(D_OBJS_STACK)
	$(CC) -o $(D_NAME_STACK) $(D_OBJS_STACK) $(LDFLAGS)

tests-token: $(D_OBJS_TOKEN)
	$(CC) -o $(D_NAME_TOKEN) $(D_OBJS_TOKEN) $(LDFLAGS)

tests-shyard: $(D_OBJS_SHYARD)
	$(CC) -o $(D_NAME_SHYARD) $(D_OBJS_SHYARD) $(LDFLAGS)

tests: tests-queue tests-stack tests-token tests-shyard

clean:
	$(RM) $(OBJS)
	$(RM) $(D_OBJS_STACK)
	$(RM) $(D_OBJS_QUEUE)
	$(RM) $(D_OBJS_TOKEN)
	$(RM) $(D_OBJS_SHYARD)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(D_NAME_STACK)
	$(RM) $(D_NAME_QUEUE)
	$(RM) $(D_NAME_TOKEN)
	$(RM) $(D_NAME_SHYARD)

re: fclean all
