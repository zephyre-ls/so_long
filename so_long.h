/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:41:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/15 17:53:53 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"

//Structure globale du jeu qui fait appel aux autres struct
typedef struct s_game
{
	t_window	window;
	t_map	map;
	t_player	player;
	t_collectibles	collectibles;
	t_exit	exit;
	t_control	control;
}		t_game;


//struct fenêtre 
typedef struct	s_window
{
}		t_window;

typedef struct	s_map
{
}		t_map;

typedef struct s_player
{
}		t_player;

// Etant donné qu'ils y aura plusieurs collectibles à récupérer dans un seul ordre :
typedef struct	s_collectible1
{
}		t_collectibles1;

typedef struct	s_collectible2
{
}		t_collectibles2;

typedef struct	s_collectible3
{
}		t_collectibles3;

typedef struct	s_collectible4
{
}		t_collectibles4;

//Les ennemies se décrémente. Un collectible pris = 1 ennemie en moins
typedef struc	s_monster1
{
} t_monster1;
typedef struc	s_monster2
{
} t_monster2;
typedef struc	s_monster3
{
} t_monster3;
typedef struc	s_monster4
{
} t_monster4;


typedef struct	s_exit
{
}		t_exit

typedef struct	s_control
{
}		t_control

typedef struct	s_counter
{
}		t_counter

typedef	struct	s_assets
{
	void	*player_img;
	void	*wall_img;
	void	*collectibles_img;
	void	*exit_img;
	void	*background_img;
	void	*ennemies_img;
}	t_assets;

#endif
