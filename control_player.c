/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:01:10 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/22 13:17:53 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	move_player(keycode, game);
	return (0);
}

void	init_controls(t_game *game)
{
	game->control.up = 122; //119;
	game->control.down = 115;
	game->control.left = 113; //97;
	game->control.right = 100;
	game->control.quit = 65307;
	game->control.reset = 114;
}

int move_player(int keycode, t_game *game)
{
	int new_x = game->player.x;
	int new_y = game->player.y;
	
	if (keycode == game->control.up)
		new_y--;
	else if (keycode == game->control.down)
		new_y++;
	else if (keycode == game->control.right)
		new_x++;
	else if (keycode == game->control.left)
		new_x--;
	else if (keycode == game->control.reset)
		reset_game(game);
	else if (keycode == game->control.quit)
	{
		mlx_destroy_window(game->window.mlx, game->window.win);
		exit (0);
	}
  if (game->map.map[new_y][new_x] != '1')
	{
		game->map.map[game->player.y][game->player.x] = '0';
		game->player.x = new_x;
		game->player.y = new_y;
		collect_collectibles(game);
		check_collision_ennemies(game);
		game->map.map[new_y][new_x] = 'P';
		player_win(game);
		draw_map(game);
	}
	return 0;
}

void	reset_game(t_game *game)
{
	dl_map(game);
	create_asset(&game->assets, &game->window);
	draw_map(game);
}
/*int	move_player(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (keycode == game->control.up)
		new_y--;
	else if (keycode == game->control.down)
		new_y++;
	else if (keycode == game->control.right)
		new_x++;
	else if (keycode == game->control.left)
		new_x--;
	else if (keycode == game->control.quit)
	{
		mlx_destroy_window(game->window.mlx, game->window.win);
		exit (0);
	}
	if (game->map.map[new_y][new_x] != '1')
	{
		printf("Avant déplacement - Joueur: (%d, %d)\n", game->player.x, game->player.y);
printf("Case visée: %c\n", game->map.map[new_y][new_x]);
		if (game->map.map[new_y][new_x] == 'C')
		{
			printf("Avant déplacement - Joueur: (%d, %d)\n", game->player.x, game->player.y);
			printf("Case visée: %c\n", game->map.map[new_y][new_x]);
		//	game->map.map[new_y][new_x] = '0';	
			collect_collectibles(game);
		}
		game->map.map[game->player.y][game->player.x] = '0';
		game->player.x = new_x;
		game->player.y = new_y;
		check_collision_ennemies(game);
		game->map.map[new_y][new_x] = 'P';
		player_win(game);
		draw_map(game);
		game->map.map[game->player.y][game->player.x] = '0'; // rajouter || 'T' = background du code
		game->player.x = new_x;
		game->player.y = new_y;
		check_collision_ennemies(game);
		game->map.map[new_y][new_x] = 'P';
		if (game->collectible_count > 0)
			collect_collectibles(game);
		player_win(game);
		draw_map(game);
	}
	return (0);
}*/

int	cant_move_wall(int new_x, int new_y, t_game *game)
{
	if (game->map.map[new_y][new_x] == '1')
		return (1);
	return (0);
}
