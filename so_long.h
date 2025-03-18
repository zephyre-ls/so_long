/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:41:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/18 10:08:54 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "GNL/get_next_line.h"

# define MAX_COLLECTIBLES 4
# define MAX_MONSTERS 4

//struct fenêtre 
typedef struct	s_window
{
	void	*mlx;
	void	*win;
	int	largeur;
	int	longeur;
}		t_window;

typedef struct	s_map
{
	int	largeur;
	int	longeur;
	char	**map;
}		t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	score;
	void	*player_img;
}		t_player;

// Etant donné qu'ils y aura plusieurs collectibles à récupérer dans un seul ordre :
typedef struct	s_collectibles
{
	int	x;
	int	y;
	int	is_collected; //(0 = false, 1 = true)
}		t_collectibles;

typedef struct	s_collectibles_type
{
	t_collectibles c1;
	t_collectibles c2;
	t_collectibles c3;
	t_collectibles c4;
}		t_collectibles_type;


//Les ennemies se décrémente. Un collectible pris = 1 ennemie en moins
typedef struct	s_monsters
{
	int	x;
	int	y;
	int	is_dead;
} t_monsters;

typedef struct	s_monsters_type
{
	t_monsters m1;
	t_monsters m2;
	t_monsters m3;
	t_monsters m4;
} 	t_monster_type;


typedef struct	s_exit
{
	int	x;
	int	y;
	int	is_open;
}		t_exit;

typedef struct	s_control
{
	int	up; //Z
	int	down; //S
	int	left; //Q
	int	right; //D
	int	quit; //ESC
}		t_control;

typedef struct	s_counter
{
	int	moves;
}		t_counter;

typedef	struct	s_assets
{
	void	*player_img;
	void	*wall_img;
	void	*collectibles_img;
	void	*exit_img;
	void	*background_img;
	void	*monster_img;
}	t_assets;

//Structure globale du jeu qui fait appel aux autres struct
typedef struct s_game
{
	t_window	window;
	t_map	map;
	t_player	player;
	t_collectibles	collectibles[MAX_COLLECTIBLES];
	t_monsters	monsters[MAX_MONSTERS];
	t_exit	exit;
	t_control	control;
	t_assets	assets;
	t_counter	counter;
}		t_game;


//Fonctions

// Map
void	draw_map(t_game *game);
void	dl_map(t_game *game/*, char *map*/);
void	create_asset(t_assets *assets, t_window *mlx);

// PLayers
int	cant_move_wall(int new_x, int new_y, t_game *game);
int	move_player(int keycode, t_game *game);

// control
void	init_controls(t_game *game);
int	key_hook(int keycode, t_game *game);

#endif
