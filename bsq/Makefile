NAME=bsq

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS=$(shell find . -name '*.c')
OBJS=$(SRCS:%.c=%.o)
HDRS=$(shell find . -name '*.h')

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	rm -f "parkbae.file"

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
