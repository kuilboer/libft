
# SHELL := bash
NAME = libft.a

# source files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I.

.PHONY: all clean fclean re

%.o: %.c
	@echo $?
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@echo "Removing object files."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing compiled output files." 
	@rm -f $(NAME)

re: fclean all