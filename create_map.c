/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:00:06 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/18 11:14:25 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//load image asset, struct des assets, pe add structure du game avec mlx ? 
void	create_asset(t_assets *assets, t_window *mlx)
{
	int	img_l;
	int	img_h;

	assets->wall_img = mlx_xpm_file_to_image(mlx->mlx, "asset/wall/Space_Stars1.xpm", &img_l, &img_h);
	assets->background_img = mlx_xpm_file_to_image(mlx->mlx, "asset/background/Space_Stars6.xpm", &img_l, &img_h);
	assets->exit_img = mlx_xpm_file_to_image(mlx->mlx, "asset/exit/ibm5150.xpm", &img_l, &img_h);
	assets->player_img = mlx_xpm_file_to_image(mlx->mlx, "asset/player/player.xpm", &img_l, &img_h);
	assets->collectibles_img = mlx_xpm_file_to_image(mlx->mlx, "asset/collectibles/collectible1.xpm", &img_l, &img_h);
	assets->monster_img = mlx_xpm_file_to_image(mlx->mlx, "asset/ennemies/monster.xpm", &img_l, &img_h);
}

void	dl_map(t_game *game/*, char *map*/)
{
	int	fd;
	int	y;
	char	*line;
	
	fd = open ("maps/map1.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("erreur ouverture fichier");
		exit(EXIT_FAILURE);
	}
	game->map.map = malloc(sizeof(char *) * 100);
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
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;
	int	pxl = 32;

	y = 0;
	while(game->map.map[y])
	{
		x=0;
		while(game->map.map[y][x])
		{
			if(game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.wall_img, x * pxl, y * pxl);
			else if(game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.background_img, x * pxl, y * pxl);
			else if(game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.player_img, x * pxl, y * pxl);			else if(game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.exit_img, x * pxl, y * pxl);
			else if(game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.collectibles_img, x * pxl, y * pxl);
			else if(game->map.map[y][x] == 'M')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->assets.monster_img, x * pxl, y * pxl);
			x++;
		}
		y++;
	}
}
