SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = libft.a
CC = gcc
CFALGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME} :	${OBJS}
	ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean :	clean
	rm -f ${NAME}

re :	fclean all
