NAME = fract-ol
LIB = ./include/fractol.h
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
PRINTF_DIR = ./printf
PRINTF = ./printf/lib_printf.a
MLX_DIR = ./mlx_linux
C_SOURCES = ./source/main.c ./source/render.c ./source/clean.c ./source/interface.c ./source/fractals.c ./source/hooks.c
OBJ = $(C_SOURCES:.c=.o)
REMOVE = @rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all:		$(NAME)

$(NAME):	$(C_SOURCES)
			@$(MAKE) --no-print-directory -C $(PRINTF_DIR)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
			@$(MAKE) --no-print-directory -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(^) $(MLX_FLAGS) -o $(@) $(PRINTF) $(LIBFT) -fsanitize=address
bonus:

clean:
			$(REMOVE) *.o
			@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
			@$(MAKE) --no-print-directory -C $(MLX_DIR) clean
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean:		clean
			$(REMOVE) $(NAME)
			@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
			@$(MAKE) --no-print-directory -C $(MLX_DIR) clean
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

re:			fclean all

.PHONY: 	all bonus clean fclean re
