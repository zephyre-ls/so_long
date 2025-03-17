/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:45 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/17 12:33:59 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//fonction pour trouver le keycode des touches
//Echap = 65307, Z=122, Q=113, S = 115, D=100, Space = 32
int	key_hook(int keycode, t_game *game)
{
	printf("le keycode est: %d\n", keycode);
	if (keycode == 65307) //press echap la fenetre se ferme
	{
		mlx_destroy_window(game->window.mlx, game->window.win); //fonction de nettoyage
		exit (0);

	}
	return(0);
}


//load image asset, struct des assets, pe add structure du game avec mlx ? 
void	create_asset(t_assets *assets, t_window *mlx)
{
	int	img_l;
	int	img_h;

	assets->wall_img = mlx_xpm_file_to_image(mlx->mlx, "asset/wall/Space_Stars1.xpm", &img_l, &img_h);
	assets->background_img = mlx_xpm_file_to_image(mlx->mlx, "asset/background/Space_Stars2.xpm", &img_l, &img_h);
	assets->exit_img = mlx_xpm_file_to_image(mlx->mlx, "asset/exit/ibm5150.xpm", &img_l, &img_h);
/*	assets->player_img = mlx_xpm_file_to_image(mlx->mlx, "asset/background/Space_Stars1.xpm", &img_l, &img_h);
	assets->collectible_img = mlx_xpm_file_to_image(mlx->mlx, "asset/background/Space_Stars1.xpm", &img_l, &img_h);
	assets->monster_img = mlx_xpm_file_to_image(mlx->mlx, "asset/background/Space_Stars1.xpm", &img_l, &img_h);*/
}

void	map(t_game *game)
{

	int	y;
	int	x;
	int	pxl = 32;
	int	fd;
	char	*line;
	
	fd = open ("maps/map1.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("erreur ouverture fichier");
		exit(EXIT_FAILURE);
	}
	game->map.map = malloc(sizeof(char *) * 10000000);
	if (!game->map.map)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	y = 0;
	while((line = get_next_line(fd)))
	{
		printf("Ligne %d: %s", y, line);
		game->map.map[y] = line;
		y++;
	}
	game->map.map[y] = NULL;
	close (fd);
	y = 0;
	while(game->map.map[y])
	{
		x=0;
		while(game->map.map[y][x])
		{
			if(game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.wall_img, x * pxl, y* pxl);
			else if(game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.background_img, x * pxl, y * pxl);
		//	else if(game->map.map[y][x] == 'P')
		//		mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.player_img, x * pxl, y * pxl);
			else if(game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.exit_img, x * pxl, y * pxl);
		//	else if(game->map.map[y][x] == 'C')
			//	mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.collectibles_img, x * pxl, y * pxl);
			x++;
		}
		y++;
	}
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
//	int	img_width = 32;
//	int	img_height = 32;

	game.window.mlx = mlx_init();
	game.window.win = mlx_new_window(game.window.mlx, 800, 600, "test");


	//mlx_string_put(game.window.mlx, game.window.win, 200, 200, 0xFF0000, "grosse chips");
	create_asset(&game.assets, &game.window);
	mlx_key_hook(game.window.win, key_hook, &game);

	map(&game);

	mlx_loop(game.window.mlx);
	return (0);
}

