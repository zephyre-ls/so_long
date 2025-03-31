/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:41:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/31 18:38:28 by npederen         ###   ########.fr       */
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
	char	*name;
}		t_map;

typedef struct s_player
{
	int		x;
	int		y;
	void	*player_img;
	int		player_count;
}		t_player;

typedef struct s_collectibles
{
	int	x;
	int	y;
	int	id; //pour l'ordre de récup des collectibles
	int	is_collected; //(0 = false, 1 = true)
}		t_collectibles;

typedef struct s_monsters
{
	int	x;
	int	y;
}		t_monsters;

typedef struct s_exit
{
	int	x;
	int	y;
	int	is_open;
	int	exit_count;
}		t_exit;

typedef struct s_floodfill
{
	int	x;
	int	y;
}		t_floodfill;

typedef struct s_control
{
	int	up_z; //Z
	int	up_w; //w
	int	down; //S
	int	right; //D
	int	left_a; //A
	int	left_q; //Q
	int	arrow_up;
	int	arrow_down;
	int	arrow_right;
	int	arrow_left;
	int	quit; //ESC
}		t_control;

typedef struct s_score
{
	int	s_count;
}		t_score;

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
	void	*player_up_img;
	void	*player_down_img;
	void	*player_left_img;
	void	*player_right_img;
}		t_assets;

//Structure globale du jeu qui fait appel aux autres struct
typedef struct s_game
{
	t_window		window;
	t_map			map;
	t_player		player;
	t_player		start_position;
	int				moves_count;
	t_collectibles	collectibles[MAX_COLLECTIBLES];
	int				collectible_count;
	int				next_collectible;
	t_monsters		monsters[MAX_MONSTERS];
	int				monster_count;
	t_exit			exit;
	t_control		control;
	t_assets		assets;
	t_score			score;
}			t_game;

//Fonctions
// Map
void	dl_map(t_game *game);
void	init_game_counters(t_game *game);

//check_map
void	dl_map_check(t_game *game, int fd);
int		check_map_wall(t_game *game);
int		check_map_rectangle(t_game *game);
int		check_way_valid(t_game *game);
void	check_name(char *name);
void	check_map_min(t_game *game);
void	map_wall_error(t_game *game);
void	check_map_validity(t_game *game, int fd);
void	check_map_accessibility(t_game *game, int fd);
void	assignation_line(t_game *game, char *line, int y);
void	gestion_player(t_game *game, int x, int y);
void	gestion_exit(t_game *game, int x, int y);
void	gestion_monster(t_game *game, int x, int y);
void	gestion_collectible(t_game *game, int x, int y);
void	check_chars(char **map, t_game *game);
int		flood_fill(t_map *map, t_game *game, int current_row, int current_col);
int		is_tiles_e(t_map *map, int y, int x, int elem);
int		check_collect_acces_block(t_game *game);

//create_map
void	draw_map(t_game *game);
void	draw_other(t_game *game, int x, int y, char other);
void	draw_collectibles(t_game *game, int x, int y);
void	draw_score(t_game *game, int x, int y, int *s_count);
void	create_asset(t_assets *assets, t_window *mlx);
void	create_asset2(t_assets *assets, t_window *mlx);

//utils
int		ft_strcmp(char *s1, char *s2);
char	**map_copy(t_game *game);
void	*ft_memcopy(char *dest, char *src, size_t n);

// PLayers
int		move_player(int keycode, t_game *game);
void	display_move_count(t_game *game, int x, int y);
void	display_moves(t_game *game);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
int		ft_len(int n);
void	update_player_position(t_game *game, int new_x, int new_y);
int		count_line(char *filename);

// control
void	gestion_move(int keycode, int *nx, int *ny, t_game *game);
int		can_move(int nx, int ny, t_game *game);
void	control_player(int keycode, int *new_x, int *new_y, t_game *game);
void	init_controls(t_game *game);
int		key_hook(int keycode, t_game *game);
int		mouse_hook(int mousecode, t_game *game);
int		mouse_click_left(int mousecode, t_game *game);
int		close_window(t_game *game);

//Collectibles
void	collect_collectibles(t_game *game);
void	error_collectible(t_game *game);

//Ennemies
void	check_collision_ennemies(t_game *game);
void	move_ennemies(t_game *game);
int		genere_move_ennemies(t_game *game, int i);
void	update_ennemies_position(t_game *game, int new_x, int new_y, int i);

// victoire
void	player_win(t_game *game);

// Reset map
void	reset_game(t_game *game);

// FREE
void	free_exit(t_game *game);
void	free_map(char **map);
void	free_image(t_game *game);
void	free_image2(t_game *game);
void	free_image3(t_game *game);
void	exit_free_failure(t_game *game);
void	exit_free(t_game *game);

#endif
