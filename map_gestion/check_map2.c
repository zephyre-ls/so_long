/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:47:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/31 18:38:59 by npederen         ###   ########.fr       */
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

int	is_tiles_e(t_map *map, int y, int x, int elem)
{
	map->map[y][x] = '1';
	return (elem + 1);
}

int	flood_fill(t_map *map, t_game *game, int y, int x)
{
	static int	elem = 0;
	static int	i = 0;

	if (y < 0 || y >= map->longeur || x < 0 || x >= map->largeur || \
		map->map[y][x] == '1' || map->map[y][x] == 'E' || map->map[y][x] == 'M')
	{
		if (map->map[y][x] == 'E')
			elem = is_tiles_e(map, y, x, elem);
		return (0);
	}
	if (map->map[y][x] == 'C')
	{
		elem++;
		map->map[y][x] = '1';
		if (game->collectibles[i].x == x && game->collectibles[i].y == y)
			i++;
		else
			return (0);
	}
	map->map[y][x] = '1';
	flood_fill(map, game, y, x - 1);
	flood_fill(map, game, y, x + 1);
	flood_fill(map, game, y - 1, x);
	flood_fill(map, game, y + 1, x);
	return (elem);
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
