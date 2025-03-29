/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 01:32:33 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/29 03:30:19 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_move(int nx, int ny, t_game *game)
{
	return (game->map.map[ny][nx] != '1' && game->map.map[ny][nx] != 'E');
}

void	gestion_move_exit_close(int keycode, int *nx, int *ny, t_game *game)
{
	if ((keycode == game->control.up_w || keycode == game->control.up_z
			|| keycode == game->control.arrow_up)
		&& can_move(*nx, *ny - 1, game))
		(*ny)--;
	else if ((keycode == game->control.down
			|| keycode == game->control.arrow_down)
		&& can_move(*nx, *ny + 1, game))
		(*ny)++;
	else if ((keycode == game->control.right
			|| keycode == game->control.arrow_right)
		&& can_move(*nx + 1, *ny, game))
		(*nx)++;
	else if ((keycode == game->control.left_a || keycode == game->control.left_q
			|| keycode == game->control.arrow_left)
		&& can_move(*nx - 1, *ny, game))
		(*nx)--;
}

void	gestion_move_exit_open(int keycode, int *nx, int *ny, t_game *game)
{
	if (keycode == game->control.up_w || keycode == game->control.up_z
		|| keycode == game->control.arrow_up)
	{
		if (game->map.map[*ny - 1][*nx] != '1')
			(*ny)--;
	}
	else if (keycode == game->control.down
		|| keycode == game->control.arrow_down)
	{
		if (game->map.map[*ny + 1][*nx] != '1')
			(*ny)++;
	}
	else if (keycode == game->control.right
		|| keycode == game->control.arrow_right)
	{
		if (game->map.map[*ny][*nx + 1] != '1')
			(*nx)++;
	}
	else if (keycode == game->control.left_a || keycode == game->control.left_q
		|| keycode == game->control.arrow_left)
	{
		if (game->map.map[*ny][*nx - 1] != '1')
			(*nx)--;
	}
}
