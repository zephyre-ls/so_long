/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/22 13:44:45 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collision_ennemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAX_MONSTERS)
	{
		if (game->player.x == game->monsters[i].x
			&& game->player.y == game->monsters[i].y)
		{
			printf("GAME OVER");
			mlx_destroy_window(game->window.mlx, game->window.win);
			exit(0);
		}
		i++;
	}
}

void	move_ennemies(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;
	int	direction;

	//fonction rand ?
	
	direction = //fonction rand
	
	new_x = game->monster[i].x;
	new_y = game->monster[i].y;

	if (direction == 0) //Haut
		new_y--;
	if (direction == 1) // Bas
		new_y++;
	if (direction == 2) //Droite
		new_x++;
	if (direction == 3) //Gauche
		new_x--;

	if (game->map.map[new_y][new_x] != '1')
	{
		game->map.map[game->monster[i].y][game->monsters[i].x] = '0';
		game->monster[i].x = new_x;
		game->monster[i].y = new_y;
		game->map.map[new_y][new_x] = 'M';
	}
}
