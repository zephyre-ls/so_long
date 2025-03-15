/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:41:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/15 17:29:33 by lduflot          ###   ########.fr       */
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


}		t_player

typedef struct	s_collectible
{

}		t_collectibles

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
