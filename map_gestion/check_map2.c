/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:47:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 19:54:40 by lduflot          ###   ########.fr       */
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
	static int	i = 0;

	//int	*tmp_id = &game->collectibles[i].id;
	int	*tmp_x = &game->collectibles[i].x;
	int	*tmp_y = &game->collectibles[i].y;
	int	tmp_next = game->next_collectible;
	int	tmp_count = game->collectible_count;

	if (current_row < 0 || current_row >= map->longeur || current_col < 0
		|| current_col >= map->largeur
		|| map->map[current_row][current_col] == '1' || map->map[current_row][current_col] == 'E')
		return (0);
	while(i < tmp_count)
	{
		if(tmp_x[i] == current_row && tmp_y[i] == current_col)
		{
			if (game->collectibles[i].id == tmp_next)
			{
				elem_collected++;
				tmp_next++;
			}
			else
				return(elem_collected);
		//	game->collectible.is_collect = 1;
		}
		i++;
	}
	if (map->map[current_row][current_col] == 'E')
		elem_collected++;
	map->map[current_row][current_col] = '1';
	flood_fill(map, game, current_row, current_col - 1);
	flood_fill(map, game, current_row, current_col + 1);
	flood_fill(map, game, current_row - 1, current_col);
	flood_fill(map, game, current_row + 1, current_col);
	return (elem_collected);
}

/*if (int id_0
int	id_1 =
int	id_2 =
int	id_3 =
int	id_4 =
*/
/*Ou alors, je cherche juste a savoir si id collectible peut etre collecte en premier sans etre entoure de
mur ou de sortie ahhh
Donc SI */
/*int	flood_fill_order_collectible(t_map *map, t_game *game, int current_row, int current_col)
{
	int	elem_collected = 0;
	int	i = 0;
	int	*tmp_x = &game->collectibles[i].x;
	int	*tmp_y = &game->collectibles[i].y;
	int	*tmp_id = &game->collectibles[i].id;
	int	tmp_next = game->next_collectible;

	if (current_row < 0 || current_row >= map->longeur || current_col < 0
		|| current_col >= map->largeur
		|| map->map[current_row][current_col] == '1' || map->map[current_row][current_col] == 'E')
		return (0);
	//elem_collected=0;
	if(map->map[current_row][current_col] == 'C')
	{
		i = 0;
		while(i <= game->collectible_count)
		{
				if (tmp_x[i] == current_col && tmp_y[i] == current_row
				&& tmp_id[i] == tmp_next)
				{
					elem_collected++;
					tmp_id[i]++;
					tmp_next++;
					printf("tmp_id %d\n", tmp_id[i]);
					printf("tmp_next %d\n", tmp_next);
					printf("elem_collect %d \n", elem_collected);
				}
				i++;
		}
	}
	map->map[current_row][current_col] = '1';
	elem_collected += flood_fill_order_collectible(map, game, current_row, current_col - 1);
	elem_collected += flood_fill_order_collectible(map, game, current_row, current_col + 1);
	elem_collected += flood_fill_order_collectible(map, game, current_row - 1, current_col);
	elem_collected += flood_fill_order_collectible(map, game, current_row + 1, current_col);
	//printf("elem_collected %d\n", elem_collected);
	return (elem_collected);
}*/

/*void	collect_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectible_count)
	{
		if (game->collectibles[i].x == game->player.x
			&& game->collectibles[i].y == game->player.y
			&& !game->collectibles[i].is_collected)
		{
			if (game->collectibles[i].id == game->next_collectible)
			{
				game->collectibles[i].is_collected = 1;
				game->next_collectible++;
				if (game->next_collectible == game->collectible_count)
				{
					game->exit.is_open = 1;
					game->map.map[game->exit.y][game->exit.x] = 'E';
				}
			}
			else
				error_collectible(game);
		}
		i++;
	}
	draw_map(game);
}*/
