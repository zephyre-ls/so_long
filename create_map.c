/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:00:06 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/24 10:51:48 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//load image asset, struct des assets, pe add structure du game avec mlx ? 
void	create_asset(t_assets *assets, t_window *mlx)
{
	int	img_l;
	int	img_h;

	assets->wall_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/wall/server.xpm", &img_l, &img_h);
	assets->background_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/background/ciel.xpm", &img_l, &img_h);
	assets->exit_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/exit/ibm5150.xpm", &img_l, &img_h);
	assets->exit_open_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/exit/open.xpm", &img_l, &img_h);
	assets->player_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/player/player.xpm", &img_l, &img_h);
	assets->monster_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/ennemies/monster.xpm", &img_l, &img_h);
	assets->collectibles_img[0] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect1.xpm", &img_l, &img_h);
	assets->collectibles_img[1] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect2.xpm", &img_l, &img_h);
	assets->collectibles_img[2] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect3.xpm", &img_l, &img_h);
	assets->collectibles_img[3] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect4.xpm", &img_l, &img_h);
	assets->collectibles_img[4] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect5.xpm", &img_l, &img_h);
	assets->code_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/code/code.xpm", &img_l, &img_h);
}

void	dl_map(t_game *game)
{
	int		fd;
	int		y;
	int		x;
	int		count_p = 0;
	int		count_e = 0;
	char	*line;

	fd = open (game->map.name, O_RDONLY);
	if (fd == -1)
	{
		perror("erreur ouverture fichier");
		exit_free_failure(game);
	}
	game->map.map = malloc(sizeof(char *) * 20);
	game->monster_count = 0;
	game->collectible_count = 0;
	game->moves_count = 0;
	if (!game->map.map)
	{
		perror("error");
		exit_free_failure(game);
	}
	y = 0;
	while ((line = get_next_line(fd)))
	{
		game->map.map[y] = line;
		x = 0;
		while (line[x])
		{
			if (line[x] == 'P')
			{
				if (count_p > 0)
				{
					perror("Mode multi non pris en charge\n");
					exit_free_failure(game);
				}
				game->player.x = x;
				game->player.y = y;
				game->start_position.x = game->player.x;
				game->start_position.y = game->player.y;
				count_p++;
			}
			else if (line[x] == 'E')
			{
				if (count_e > 0)
				{
					perror("Une seule sortie autorisé\n");
					exit_free_failure(game);
				}
				game->exit.x = x;
				game->exit.y = y;
				game->exit.is_open = 0;
				count_e++;
			}
			else if (line[x] == 'M')
			{
				if (game->monster_count < MAX_MONSTERS)
				{
					game->monsters[game->monster_count].x = x;
					game->monsters[game->monster_count].y = y;
					game->monster_count++;
				}
				else
					exit_free_failure(game);
			}
			else if (line[x] == 'C')
			{
				if (game->collectible_count < MAX_COLLECTIBLES)
				{
					game->collectibles[game->collectible_count].x = x;
					game->collectibles[game->collectible_count].y = y;
					game->collectibles[game->collectible_count].id = game->collectible_count;
					game->collectibles[game->collectible_count].is_collected = 0;
					game->next_collectible = 0;
				//	printf("Collectible chargé: collect_count = %d, ID = %d, X = %d, Y = %d\n",game->collectible_count, game->collectibles[game->collectible_count].id, x, y);
					game->collectible_count++;
				}
				else
					exit_free_failure(game);
			}
			x++;
		}
		y++;
	}
	game->map.largeur = x;
	game->map.longeur = y;
	game->map.map[y] = NULL;
	check_chars(game->map.map, game);
	if (!check_map_wall(game))
	{
		perror("Erreur, la carte n'est pas entourée de mur\n");
		exit_free_failure(game);
	}
	close (fd);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;
	int	pxl;
	int	i;

	y = 0;
	pxl = 64;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->assets.wall_img, x * pxl, y * pxl);
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->assets.background_img, x * pxl, y * pxl);
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->assets.player_img, x * pxl, y * pxl);
			else if (game->map.map[y][x] == 'E')
			{
				if (game->exit.is_open)
					mlx_put_image_to_window(game->window.mlx, game->window.win,
						game->assets.exit_open_img, x * pxl, y * pxl);
				else
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->assets.exit_img, x * pxl, y * pxl);
			}
			else if (game->map.map[y][x] == 'C')
			{
				i = 0;
				while (i < MAX_COLLECTIBLES)
				{
					if (game->collectibles[i].x == x && game->collectibles[i].y == y
						&& game->collectibles[i].is_collected == 0)
					{
						mlx_put_image_to_window(game->window.mlx, game->window.win,
						game->assets.collectibles_img[i], x * pxl, y * pxl);
					}
					i++;
				}
			}
			else if (game->map.map[y][x] == 'M')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->assets.monster_img, x * pxl, y * pxl);
			else if (game->map.map[y][x] == 'T')
				mlx_put_image_to_window(game->window.mlx, game->window.win,
					game->assets.code_img, x * pxl, y * pxl);
			x++;
		}
		y++;
	}
}
