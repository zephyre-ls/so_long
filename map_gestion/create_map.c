/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:00:06 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 00:05:37 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			draw_other(game, x, y, game->map.map[y][x]);
			if (game->map.map[y][x] == 'C' || game->map.map[y][x] == 'T')
				draw_collectibles(game, x, y);
			x++;
		}
		y++;
	}
}

void	draw_collectibles(t_game *game, int x, int y)
{
	int	i;
	int	pxl;

	pxl = 64;
	i = 0;
	while (i <= MAX_COLLECTIBLES)
	{
		if (game->collectibles[i].x == x && game->collectibles[i].y == y
			&& game->collectibles[i].is_collected == 0)
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->assets.collectibles_img[i], x * pxl, y * pxl);
		}
		i++;
	}
	if (game->map.map[y][x] == 'T')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->assets.code_img, x * pxl, y * pxl);
}

void	draw_other(t_game *game, int x, int y, char other)
{
	int	pxl;

	pxl = 64;
	if (other == '1')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->assets.wall_img, x * pxl, y * pxl);
	else if (other == '0')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->assets.background_img, x * pxl, y * pxl);
	else if (other == 'P')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->assets.player_img, x * pxl, y * pxl);
	else if (other == 'E')
	{
		if (game->exit.is_open)
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->assets.exit_open_img, x * pxl, y * pxl);
		else
			mlx_put_image_to_window(game->window.mlx, game->window.win,
				game->assets.exit_img, x * pxl, y * pxl);
	}
	else if (other == 'M')
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->assets.monster_img, x * pxl, y * pxl);
}
//Ft pour asset_score
/*void	draw_score(t_game *game, int x, int y, int *s_count)
{
	if (*s_count < 3)
	{
		game->score.x[*s_count] = x;
		game->score.y = y;
		(*s_count)++;
		display_move_count(game, x * 64, y * 64);
	}
}*/
