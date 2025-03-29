# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:26 by lduflot           #+#    #+#              #
#    Updated: 2025/03/29 09:19:57 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
##-ggdb, -g3
NAME = so_long

###############################
##SOURCES

GNL_FILES = GNL/get_next_line.c \
  					GNL/get_next_line_utils.c
FILES = so_long.c \
				map_gestion/dl_map.c \
				map_gestion/create_map.c \
				map_gestion/create_map_utils.c \
				game/control_player.c \
				game/control_player_utils.c \
				game/control_key.c \
				game/ennemies_kill.c \
				game/collect_collectibles.c \
				map_gestion/check_map.c \
				map_gestion/gestion_tuile.c \
				map_gestion/check_map_utils.c \
				free/free.c \
				free/free_2.c \
				game/win.c
OBJS = $(FILES:.c=.o) $(GNL_FILES:.c=.o)

###############################
##LIBRAIRIES_MINILIBX

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

###############################
##RULES

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@echo "Compilation de la minilibx..."
	@make -C $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS)
	@echo "Lancement du jeu..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I GNL -c $< -o $@

clean:
	@echo "Deleting object files : .o"
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean || true

fclean: clean
	@echo "Deleting object files and executable"
	@rm -f $(NAME)
	@make -C $(MLX_DIR) fclean || true

re: fclean all

.PHONY: all clean fclean re

