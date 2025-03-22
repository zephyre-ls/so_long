/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/22 21:00:24 by lduflot          ###   ########.fr       */
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

int	genere_move_ennemies(t_game *game, int i)
{
	int x = game->player.x;
	int	y = game->player.y;
	int	somme = x + y + game->monsters[i].x + game->monsters[i].y;
	
	return(somme%4)+1;
}

void	move_ennemies(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;
	int	direction;

	//fonction rand ?
	
	//direction = //fonction rand
	i = 0;
	while(i < MAX_MONSTERS)
	{
		direction = genere_move_ennemies(game, i);
	
	new_x = game->monsters[i].x;
	new_y = game->monsters[i].y;

	if (direction == 1) //Haut
		new_y--;
	if (direction == 2) // Bas
		new_y++;
	if (direction == 3) //Droite
		new_x++;
	if (direction == 4) //Gauche
		new_x--;

	if (game->map.map[new_y][new_x] != '1' && game->map.map[new_y][new_x] != 'T'&&
		game->map.map[new_y][new_x] != 'C' && game->map.map[new_y][new_x] != 'E' && game->map.map[new_y][new_x] != 'M')
	{
		game->map.map[game->monsters[i].y][game->monsters[i].x] = '0';
		game->monsters[i].x = new_x;
		game->monsters[i].y = new_y;
		game->map.map[new_y][new_x] = 'M';
	}
	i++;
	}
}
