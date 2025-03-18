/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:45 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/18 10:11:19 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//fonction pour trouver le keycode des touches
//Echap = 65307, Z=122, Q=113, S = 115, D=100, Space = 32
int	key_hook(int keycode, t_game *game)
{
	move_player(keycode, game);
	return(0);
}
//fonction pour trouver le keycode de la souris
/*int	mouse_hook(int mousecode)
{
	if (mousecode == )
		 if (mousecode // rajouter cliquer croix )
				exit (0);
	return (0);
}*/

int	main(void)
{
	t_game	game;
	game.window.mlx = mlx_init();
	game.window.win = mlx_new_window(game.window.mlx, 800, 600, "test");
	create_asset(&game.assets, &game.window);

	init_controls(&game);
	dl_map(&game);
	draw_map(&game);

	mlx_key_hook(game.window.win, key_hook, &game);
	mlx_loop(game.window.mlx);
	return (0);
}

