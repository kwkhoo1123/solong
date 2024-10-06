NAME = sampletext

SRC = test.c
		
OBJS 	= ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address

MINILIBX = -lmlx -framework OpenGL -framework AppKit


.c.o:		%.o : %.c
					@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(OBJS)
			${CC} ${CFLAGS} ${SRC} ${MINILIBX} -o ${NAME}
			@echo "test compiled!"

clean:
	@make clean -C ./libft
	rm -rf *.o

fclean: clean
	@make fclean -C ./libft
	rm -f ${OBJS} $(NAME)

re: fclean all

.PHONY: all clean fclean re 