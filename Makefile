# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:26 by lduflot           #+#    #+#              #
#    Updated: 2025/03/28 01:31:55 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -ggdb -g3 -Wall -Wextra -Werror
NAME = so_long

###############################
##SOURCES

GNL_FILES = GNL/get_next_line.c \
						GNL/get_next_line_utils.c
FILES = main.c \
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

MLX_PLACE = minilibx-linux
MLXFLAGS = -I$(MLX_PLACE) -L$(MLX_PLACE) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
## -lm = lie la bibliotheque libm qui contient toute les fonctions mathematique

###############################
##RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Lancement du jeu..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_PLACE) -I GNL -c $< -o $@

clean:
	@echo "Nettoyage en cours..."
	@rm -f $(OBJS)
fclean: clean
	@echo "Nettoyage plus approndis en cours..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

