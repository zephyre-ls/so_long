/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:00:06 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/26 18:08:28 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dl_map(t_game *game)
{
	int		fd;
	int		y;
	int		x;
	int		count_p;
	int		count_e;
	char	*line;

	count_p = 0;
	count_e = 0;
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
	game->score.s_count = 0;
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
					game->collectibles[game->collectible_count].id
						= game->collectible_count;
					game->collectibles[game->collectible_count].is_collected
						= 0;
					game->next_collectible = 0;
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
		close(fd);
		exit_free_failure(game);
	}
	char **map_copied = map_copy(game);
	if(!map_copied)
	{
     perror("Erreur lors de la création de la copie de la carte\n");
			close(fd);
    	exit_free_failure(game);
  }
	if (flood_fill(map_copied, game->player.y, game->player.x, game->map.longeur, game->map.largeur) != game->collectible_count + 1)
	{
		perror("Erreur, collectible ou exit non accessible par le player \n");
			close(fd);
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
	int s_count = 0;

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
					if (game->collectibles[i].x == x
						&& game->collectibles[i].y == y
						&& game->collectibles[i].is_collected == 0)
					{
						mlx_put_image_to_window(game->window.mlx,
							game->window.win, game->assets.collectibles_img[i],
							x * pxl, y * pxl);
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
			else if (game->map.map[y][x] == 'S' && s_count < 3)
			{
			//	printf("position x %d\n", game->score.x[s_count]);
			//	printf("position y %d\n", game->score.y);
				game->score.x[s_count] = x;
				game->score.y = y;
				s_count++;
				display_move_count(game, x * 64 , y * 64 );
			}
			x++;
		}
		y++;
	}
}
