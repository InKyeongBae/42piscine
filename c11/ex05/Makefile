SRCS	= srcs/do-op.c srcs/ft_operation.c srcs/ft_atoi.c srcs/ft_putnbr.c
OBJS	= ${SRCS:.c=.o}
NAME	= do-op
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

${NAME} : all

all :
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re: fclean all
