/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:47:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 21:12:34 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_min(t_game *game)
{
	if (game->collectible_count <= 0)
	{
		write(2, "Erreur: Le nombre de collectibles doit être > 0\n", 50);
		exit_free_failure(game);
	}
	if (game->monster_count < MAX_MONSTERS)
	{
		write(2, "Erreur: Nbr monstres minimum requis = 4\n", 41);
		exit_free_failure(game);
	}
	if (game->player.player_count != 1)
	{
		write(2, "Erreur: Le nombre de player doit être = 1\n", 43);
		exit_free_failure(game);
	}
	if (game->exit.exit_count != 1)
	{
		write(2, "Erreur: Le nombre de sortie doit être = 1\n", 44);
		exit_free_failure(game);
	}
}

int	flood_fill(t_map *map, t_game *game, int current_row, int current_col)
{
	static int	elem_collected = 0;

	if (current_row < 0 || current_row >= map->longeur || current_col < 0
		|| current_col >= map->largeur
		|| map->map[current_row][current_col] == '1')
		return (0);
	if (map->map[current_row][current_col] == 'C')
		elem_collected++;
	if (map->map[current_row][current_col] == 'E')
		elem_collected++;
	map->map[current_row][current_col] = '1';
	flood_fill(map, game, current_row, current_col - 1);
	flood_fill(map, game, current_row, current_col + 1);
	flood_fill(map, game, current_row - 1, current_col);
	flood_fill(map, game, current_row + 1, current_col);
	return (elem_collected);
}

int	check_collect_acces_block(t_game *game)
{
	t_collectibles	*first;
	t_collectibles	*second;

	first = &game->collectibles[0];
	second = &game->collectibles[1];
	if (game->collectible_count < 2)
		return (0);
	if (!(game->exit.x == first->x && game->exit.y == first->y - 1))
		return (0);
	if (game->map.map[game->exit.y - 1][game->exit.x] != '1')
		return (0);
	if (game->map.map[game->exit.y][game->exit.x - 1] != '1')
		return (0);
	if (game->map.map[game->exit.y][game->exit.x + 1] != '1')
		return (0);
	if (!(second->x == first->x + 1 && second->y == first->y))
		return (0);
	return (1);
}
