/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_collectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:48:38 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/26 19:24:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_collectibles(t_game *game)
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
			{
				write(2, "Mauvais collectible collecte, rejouez.\n", 39);
				exit_free(game);
			}
		}
		i++;
	}
	draw_map(game);
}
