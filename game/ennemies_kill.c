/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/28 00:19:13 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_collision_ennemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAX_MONSTERS)
	{
		if (game->player.x == game->monsters[i].x
			&& game->player.y == game->monsters[i].y)
		{
			write(1, "GAME_OVER\n", 10);
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
	int	nx;
	int	ny;
	int	direction;

	i = 0;
	while (i < MAX_MONSTERS)
	{
		direction = genere_move_ennemies(game, i);
		nx = game->monsters[i].x;
		ny = game->monsters[i].y;
		if (direction == 1)
			ny--;
		if (direction == 2)
			ny++;
		if (direction == 3)
			nx++;
		if (direction == 4)
			nx--;
		if (game->map.map[ny][nx] != '1' && game->map.map[ny][nx] != 'T'
			&& game->map.map[ny][nx] != 'C' && game->map.map[ny][nx] != 'E'
			&& game->map.map[ny][nx] != 'M')
			update_ennemies_position(game, nx, ny, i);
		i++;
	}
}

void	update_ennemies_position(t_game *game, int new_x, int new_y, int i)
{
	game->map.map[game->monsters[i].y][game->monsters[i].x] = '0';
	game->monsters[i].x = new_x;
	game->monsters[i].y = new_y;
	game->map.map[new_y][new_x] = 'M';
}
