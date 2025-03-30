/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:03:49 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 09:10:44 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_exit(t_game *game)
{
	if (game->window.win)
	{
		free_image(game);
		free_image2(game);
		free_image3(game);
		mlx_destroy_window(game->window.mlx, game->window.win);
		game->window.win = NULL;
		mlx_destroy_display(game->window.mlx);
		free(game->window.mlx);
		game->window.mlx = NULL;
	}
	if (game ->map.map)
		free_map(game->map.map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	free_image(t_game *game)
{
	if (game->assets.player_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.player_img);
		game->assets.player_img = NULL;
	}
	if (game->assets.wall_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.wall_img);
		game->assets.wall_img = NULL;
	}
	if (game->assets.exit_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.exit_img);
		game->assets.exit_img = NULL;
	}
	if (game->assets.exit_open_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.exit_open_img);
		game->assets.exit_open_img = NULL;
	}
	if (game->assets.background_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.background_img);
		game->assets.background_img = NULL;
	}
}

void	free_image2(t_game *game)
{
	int	i;

	i = 0;
	while (i <= MAX_COLLECTIBLES)
	{
		if (game->assets.collectibles_img[i])
		{
			mlx_destroy_image(game->window.mlx,
				game->assets.collectibles_img[i]);
			game->assets.collectibles_img[i] = NULL;
		}
		i++;
	}
	if (game->assets.monster_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.monster_img);
		game->assets.monster_img = NULL;
	}
	if (game->assets.code_img != NULL)
	{
		mlx_destroy_image(game->window.mlx, game->assets.code_img);
		game->assets.code_img = NULL;
	}
}

void	free_image3(t_game *game)
{
	if (game->assets.player_up_img)
	{
		mlx_destroy_image(game->window.mlx, game->assets.player_up_img);
		game->assets.player_up_img = NULL;
	}
	if (game->assets.player_down_img)
	{
		mlx_destroy_image(game->window.mlx, game->assets.player_down_img);
		game->assets.player_down_img = NULL;
	}
	if (game->assets.player_right_img)
	{
		mlx_destroy_image(game->window.mlx, game->assets.player_right_img);
		game->assets.player_right_img = NULL;
	}
	if (game->assets.player_left_img)
	{
		mlx_destroy_image(game->window.mlx, game->assets.player_left_img);
		game->assets.player_left_img = NULL;
	}
}
