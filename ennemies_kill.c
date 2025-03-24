/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/24 11:42:31 by lduflot          ###   ########.fr       */
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
			write(1, "GAME OVER\n", 10);
			exit_free(game);
		}
		i++;
	}
}

int	genere_move_ennemies(t_game *game, int i)
{
	int	x;
	int	y;
	int	somme;
	int	aleatoire;

	x = game->player.x;
	y = game->player.y;
	somme = x + y + game->monsters[i].x + game->monsters[i].y;
	aleatoire = (somme % 4) + 1;
	return (aleatoire);
}

//1 = HAUT, 2 = BAS, 3 = DROITE, 4 = GAUCHE
void	move_ennemies(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;
	int	direction;

	i = 0;
	while (i < MAX_MONSTERS)
	{
		direction = genere_move_ennemies(game, i);
		new_x = game->monsters[i].x;
		new_y = game->monsters[i].y;
		if (direction == 1)
			new_y--;
		if (direction == 2)
			new_y++;
		if (direction == 3)
			new_x++;
		if (direction == 4)
			new_x--;
		if (game->map.map[new_y][new_x] != '1'
			&& game->map.map[new_y][new_x] != 'T'
			&& game->map.map[new_y][new_x] != 'C'
			&& game->map.map[new_y][new_x] != 'E'
			&& game->map.map[new_y][new_x] != 'M')
		{
			game->map.map[game->monsters[i].y][game->monsters[i].x] = '0';
			game->monsters[i].x = new_x;
			game->monsters[i].y = new_y;
			game->map.map[new_y][new_x] = 'M';
		}
		i++;
	}
}
