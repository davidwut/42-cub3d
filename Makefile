NAME		:= cub3d

SRC_DIR		:= src/
SRC			:= main.c

SRCS		:= $(addprefix $(SRC_DIR), $(SRC))
OBJS		:= $(SRCS:%.c=%.o)
OBJS_DIR	:= objs

MLIB		:= libmlx_Linux.a
MLX_DIR		:= mlx_linux
MLX			:= $(MLX_DIR)/$(MLIB)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -rf

RED			:=\033[0;31m
PURPLE		:=\033[0;35m
NC			:=\033[0m

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX)
			$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

$(MLX):
			$(MAKE) -C $(MLX_DIR)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

prod:		CFLAGS :=
prod:		re

run:		prod
			@echo "$(PURPLE)~~~~Running $(NAME)~~~~$(NC)"
			@./$(NAME)

.PHONY:		all clean fclean re run prod
