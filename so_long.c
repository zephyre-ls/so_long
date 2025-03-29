/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:59:25 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/29 09:26:50 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map.name = argv[1];
		check_name(argv[1]);
		game.window.mlx = mlx_init();
		if (!game.window.mlx)
		{
			perror("Erreur lors de l'initialisation de la mlx");
			exit(EXIT_FAILURE);
		}
		game.window.win = mlx_new_window(game.window.mlx, 1800, 800,
				"so_long_savoir vs black hole");
		create_asset(&game.assets, &game.window);
		create_asset2(&game.assets, &game.window);
		init_controls(&game);
		dl_map(&game);
		draw_map(&game);
		mlx_key_hook(game.window.win, key_hook, &game);
		mlx_hook(game.window.win, 17, 0, close_window, &game);
		mlx_loop(game.window.mlx);
		exit_free(&game);
	}
	else
		write(2, "Error: Programme + Nom de fichier valide attendu .ber\n", 55);
	return (0);
}
