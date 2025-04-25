
# SHELL := bash

NAME = libft.a
#HEADER = libft.h

# source files
SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.f
	@echo $?
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@

clean:
	@echo "Removing object files."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing compiled output files." 
	@rm -f $(NAME)

re: fclean all