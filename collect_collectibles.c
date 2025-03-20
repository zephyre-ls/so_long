/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_collectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:48:38 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/20 15:38:37 by lduflot          ###   ########.fr       */
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
			&& game->player.y == game->collectibles[i].y)
		{
			game->collectibles[i].is_collected = 1;
			game->map.map[game->player.y][game->player.x] = '0';
			if (i < MAX_MONSTERS)
				game->monsters[i].is_dead = 1;
		}
		break ;
	}
	i++;
}
