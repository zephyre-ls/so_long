# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:26 by lduflot           #+#    #+#              #
#    Updated: 2025/03/15 16:51:34 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = so_long

###############################
##SOURCES

FILES = main.c
OBJS = $(FILES:.c=.o)

###############################
##LIBRAIRIES_MINILIBX

MLX_PLACE = minilibx-linux
MLXFLAGS = -I$(MLX_PLACE) -L$(MLX_PLACE) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
##.B -lmlx -lXext -lX11

###############################
##RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Lancement du jeu..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_PLACE) -c $< -o $@

clean:
	@echo "Mr.Larbin nettoie..."
	@rm -f $(OBJS)
fclean: clean
	@echo "Mr.Larbin nettoie encore plus..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

