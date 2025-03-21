/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_collectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:48:38 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/21 12:07:26 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAX_COLLECTIBLES)
	{
		if (game->player.x == game->collectibles[i].x
			&& game->player.y == game->collectibles[i].y
			&& game->collectibles[i].is_collected == 0)
		{
			game->collectibles[i].is_collected = 1;
			game->collectible_count++;
			game->map.map[game->player.y][game->player.x] = '0';
			game->map.map[game->player.y][game->player.x] = 'T';
			/*if (i < MAX_MONSTERS)
				game->monsters[i].is_dead = 1;*/
		}
		//break ;
		if (game->collectible_count == MAX_COLLECTIBLES)
		{
			game->exit.is_open = 1;
			game->map.map[game->exit.y][game->exit.x] = 'E';
		}
		break ;
	}
	i++;
}
