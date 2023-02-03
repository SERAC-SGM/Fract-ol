CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	fractol.c	\
			maths.c		\
			window.c	\
			colors.c	\
			keys.c		\
			mouse.c

SRCS_DIR	= srcs/
SRCS_PATH	= $(addprefix $(SRCS_DIR), $(SRCS))

NAME	=	./fractol

DEPS	=	fractol.h	\
			maths.h		\
			window.h	\
			input.h

DEPS_DIR	= deps/
DEPS_PATH	= $(addprefix $(DEPS_DIR), $(DEPS))

OBJS		=	$(SRCS:.c=.o)
OBJS_DIR	=	objs/
OBJS_PATH	=	$(addprefix $(OBJS_DIR), $(OBJS))

#ft_printf
PRINTF_DIR = ./printf

#Minilibx
MLX_DIR		=	./minilibx-linux
CFLAGS_MLX	=	-I $(MLX_DIR)
LDFLAGS		=	-L $(MLX_DIR) -lmlx -lX11 -lXext

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(DEPS_PATH)
		mkdir -p $(OBJS_DIR)
		${CC} $(CFLAGS) -c $< -o $@

all:		$(NAME)

printf:
	@make -C $(PRINTF_DIR)

minilibx-linux: 
	@make -C $(MLX_DIR)


$(NAME): ${OBJS_PATH} minilibx-linux
	$(CC) $(CFLAGS) $(OBJS_PATH) $(CFLAGS_MLX) $(LDFLAGS) -o $(NAME) -lm

test:
	$(CC) -g $(CFLAGS) other/test.c $(CFLAGS_MLX) $(LDFLAGS) -o $(NAME).test -lm

valgrind :	${OBJS_PATH}
	$(CC) $(CFLAGS) $(OBJS_PATH) $(CFLAGS_MLX) $(LDFLAGS) -o $(NAME).vgr -g -lm

mac :		${OBJS_PATH}
	$(CC) $(OBJS_PATH) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -o $(NAME)

clean_printf:
	@make clean -C $(PRINTF_DIR)

fclean_printf:
	@make fclean -C $(PRINTF_DIR)

clean_minilibx:
	@make clean -C $(MLX_DIR)

clean: clean_minilibx clean_printf
	@rm -rf ${OBJS_DIR}

fclean:		clean fclean_printf
	@rm -f ${NAME} $(NAME).vgr $(NAME).test

re:			fclean all

.PHONY :	all valgrind mac clean fclean re
