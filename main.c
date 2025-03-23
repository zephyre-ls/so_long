/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:45 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/23 23:27:22 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//fonction pour trouver le keycode des touches
//Echap = 65307, Z=122, Q=113, S = 115, D=100, Space = 32

//fonction pour trouver le keycode de la souris
/*int	mouse_hook(int mousecode)
{
	if (mousecode == )
		 if (mousecode // rajouter cliquer croix )
				exit (0);
	return (0);
}*/
int	main(int	argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map.name = argv[1];
	//	check_name(&argv[1]);
		game.window.mlx = mlx_init();
		game.window.win = mlx_new_window(game.window.mlx, 1800, 800, "test");
		create_asset(&game.assets, &game.window);
		init_controls(&game);
		dl_map(&game);
		draw_map(&game);
		mlx_key_hook(game.window.win, key_hook, &game);
		mlx_loop(game.window.mlx);
		exit_free(&game);
	}
	else
		perror("Error/ Programme + Nom de fichier valide");
	return (0);
}

void	check_name(char **argv)
{
	int	i = 0;
	while(argv[1][i] != '\0')
		i++;
	while(i > 0)
	{
		if (argv[1][i] == 'r' && argv[1][i - 1] == 'e' && argv[1][i - 2] == 'b' && argv[1][i -3] == '.')
			return ;
		else
		{
			perror("Type de fichier accepte .ber");
			exit (0);
		}
	}
}
