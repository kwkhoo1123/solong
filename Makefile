NAME = so_long

SRC = so_long.c map.c map_update.c endgame.c pathfinding.c pathfinding_util.c \
		window.c image_init.c image_init_render.c image_destroy.c enemy.c \
		checker.c animation.c enemy_ve.c enemy_he.c draw_util.c \
		move_util.c move_left.c move_right.c move_down.c move_up.c \
		
OBJS 	= ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address

MINILIBX = -lmlx -framework OpenGL -framework AppKit

LIBFT = -L ./libft -lft

.c.o:		%.o : %.c
					@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(OBJS)
			@echo "Compiling solong"
			@make re -C ./libft
			${CC} ${CFLAGS} ${SRC} ${MINILIBX} ${LIBFT} -o ${NAME}
			@echo "Solong compiled!"

bonus: $(OBJS)
			@echo "Compiling solong"
			@make re -C ./libft
			${CC} ${CFLAGS} ${SRC} ${MINILIBX} ${LIBFT} -o ${NAME} -D BONUS=1
			@echo "Solong compiled!"

clean:
	@make clean -C ./libft
	rm -rf *.o

fclean: clean
	@make fclean -C ./libft
	rm -f ${OBJS} $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus