NAME	:= solong
CC		:= cc
SRCS	:=	main.c \
			errorcheck.c \
			maperror.c \
			free.c
OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L../libft/ -lft -L/usr/lib -lmlx -lXext -lX11 -lm -lz -Imlx -o $(NAME) -g

%.o: %.c
	$(CC) -I/usr/include -Imlx -c $< -o $@ -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re