SRCS = srcs/do-op.c srcs/calculator.c srcs/main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = includes

OBJS = ${SRCS:.c=.o}

RM = rm -f
NAME = do-op

all: ${NAME}

.c.o:
		${CC} ${CFLAGS} -c  $< -o $@ -I ${INC}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} -o  ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
