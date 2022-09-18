SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = includes

OBJS = ${SRCS:.c=.o}

RM = rm -f
NAME = libft.a

all: ${NAME}


.c.o:
		${CC} ${CFLAGS} -c  $< -o $@ -I ${INC}

${NAME}: ${OBJS}
		ar -rc $@ ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
