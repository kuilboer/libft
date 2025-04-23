
SHELL := bash
NAME = libft

# source files
SRCS = ft_isalpha.c																																																																																																																																																																																																													
OBJS = ft_isalpha.o

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) 
	cc -Wall -Wextra -Werror 
names:
	for name in SRCS; do\
		echo $$name; \
		
ft_isalpha.o: ft_isalpha.c
	cc -c $(CFLAGS)

clean:
	rm -f ./*.o


fclean:
	rm -f $(NAME) $(OBJS)


re: clean all