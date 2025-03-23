# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:26 by lduflot           #+#    #+#              #
#    Updated: 2025/03/23 19:04:12 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -ggdb -Wall -Wextra -Werror
NAME = so_long

###############################
##SOURCES

GNL_FILES = GNL/get_next_line.c \
						GNL/get_next_line_utils.c 
FILES = main.c \
				create_map.c \
				control_player.c \
				ennemies_kill.c \
				collect_collectibles.c \
				check_map.c \
				free.c \
				win.c
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
	@echo "Mr.Larbin nettoie..."
	@rm -f $(OBJS)
fclean: clean
	@echo "Mr.Larbin nettoie encore plus..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

