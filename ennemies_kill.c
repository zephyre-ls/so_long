/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/20 15:26:07 by lduflot          ###   ########.fr       */
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
