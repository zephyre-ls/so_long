/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:41:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/23 11:06:22 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "GNL/get_next_line.h"

# define MAX_COLLECTIBLES 5
# define MAX_MONSTERS 4

//struct fenêtre
typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		largeur;
	int		longeur;
}		t_window;

typedef struct s_map
{
	int		largeur;
	int		longeur;
	char	**map;
}		t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	void	*player_img;
}		t_player;

// Etant donné qu'ils y aura plusieurs collectibles à récupérer
// dans un seul ordre :
typedef struct s_collectibles
{
	int	x;
	int	y;
	int	id; //pour l'ordre de récup des collectibles
	int	is_collected; //(0 = false, 1 = true)
}		t_collectibles;

//Les ennemies se décrémente. Un collectible pris = 1 ennemie en moins
typedef struct s_monsters
{
	int	x;
	int	y;
	int	is_dead;
}		t_monsters;

typedef struct s_exit
{
	int	x;
	int	y;
	int	is_open;
}		t_exit;

typedef struct s_control
{
	int	up_z; //Z
	int	up_w; //w
	int	down; //S
	int	left_a; //A
	int	left_q; //Q
	int	arrow_up;
	int	arrow_down;
	int	arrow_right;
	int	arrow_left;
	int	right; //D
	int	quit; //ESC
	int	reset; //R
}		t_control;

typedef struct s_counter
{
	int	moves;
}		t_counter;

typedef struct s_assets
{
	void	*player_img;
	void	*wall_img;
	void	*collectibles_img[5];
	void	*exit_img;
	void	*exit_open_img;
	void	*background_img;
	void	*monster_img;
	void	*code_img;
}		t_assets;
//Structure globale du jeu qui fait appel aux autres struct
typedef struct s_game
{
	t_window	window;
	t_map		map;
	t_player	player;
	t_player	start_position;
	t_collectibles	collectibles[MAX_COLLECTIBLES];
	int			collectible_count;
	int collectible_recup;
	int			next_collectible;
	t_monsters	monsters[MAX_MONSTERS];
	int			monster_count;
	t_exit		exit;
	t_control	control;
	t_assets	assets;
	t_counter	counter;
}		t_game;

//Fonctions

// Map
void	draw_map(t_game *game);
void	dl_map(t_game *game);
void	create_asset(t_assets *assets, t_window *mlx);

// PLayers
int	cant_move_wall(int new_x, int new_y, t_game *game);
int	move_player(int keycode, t_game *game);

// control
void	control_player(int keycode, int *new_x, int *new_y, t_game *game);
void	init_controls(t_game *game);
int	key_hook(int keycode, t_game *game);

//Collectibles
void	collect_collectibles(t_game *game);

//Ennemies
void	check_collision_ennemies(t_game *game);
void	move_ennemies(t_game *game);
int	genere_move_ennemies(t_game *game, int i);

// victoire
void	player_win(t_game *game);

// Reset map
void	reset_game(t_game *game);

// FREE
void	free_exit(t_game *game);
void	free_map(char **map);

#endif
