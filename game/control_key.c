/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 01:32:33 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 20:42:59 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	gestion_move(int keycode, int *nx, int *ny, t_game *game)
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
