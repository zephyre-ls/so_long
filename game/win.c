/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:15:27 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/23 20:31:09 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_win(t_game *game)
{
	if (game->exit.is_open == 1
		&& game->player.x == game->exit.x
		&& game->player.y == game->exit.y)
	{
		printf("YOU WIN BATARD");
		exit_free(game);
	}
}
