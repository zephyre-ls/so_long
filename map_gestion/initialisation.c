/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:09:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 14:55:49 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game_counters(t_game *game)
{
	game->monster_count = 0;
	game->collectible_count = 0;
	game->moves_count = 0;
	game->score.s_count = 0;
	game->player.player_count = 0;
	game->exit.exit_count = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->exit.x = -1;
	game->exit.y = -1;
}
