/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:01:10 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/27 23:41:31 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_move_count(t_game *game, int x, int y)
{
	char	*move_str;

	move_str = ft_itoa(game->moves_count);
	if (!move_str)
		return ;
	mlx_clear_window(game->window.mlx, game->window.win);
	mlx_string_put(game->window.mlx, game->window.win, x, y,
		0xFFFFFF, "Score:");
	mlx_string_put(game->window.mlx, game->window.win, x + 50, y,
		0xFFFFFF, move_str);
	free(move_str);
}

void	control_player(int keycode, int *new_x, int *new_y, t_game *game)
{
	int	x;
	int	y;

	x = *new_x;
	y = *new_y;
	gestion_mouvement(keycode, new_x, new_y, game);
	if (keycode == game->control.quit)
		exit_free(game);
	if (*new_x != x || *new_y != y)
	{
		game->moves_count++;
		game->score.s_count++;
		write(1, "Pas : ", 6);
		ft_putnbr_fd(game->moves_count, 1);
		write(1, "\n", 1);
		display_move_count(game, 10, 780);
	}
}

void	gestion_mouvement(int keycode, int *new_x, int *new_y, t_game *game)
{
	if (keycode == game->control.up_w || keycode == game->control.up_z
		|| keycode == game->control.arrow_up)
	{
		if (game->map.map[*new_y - 1][*new_x] != '1')
			(*new_y)--;
	}
	else if (keycode == game->control.down
		|| keycode == game->control.arrow_down)
	{
		if (game->map.map[*new_y + 1][*new_x] != '1')
			(*new_y)++;
	}
	else if (keycode == game->control.right
		|| keycode == game->control.arrow_right)
	{
		if (game->map.map[*new_y][*new_x + 1] != '1')
			(*new_x)++;
	}
	else if (keycode == game->control.left_a || keycode == game->control.left_q
		|| keycode == game->control.arrow_left)
	{
		if (game->map.map[*new_y][*new_x - 1] != '1')
			(*new_x)--;
	}
}

int	move_player(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	control_player(keycode, &new_x, &new_y, game);
	if (game->map.map[new_y][new_x] != '1' && game->map.map[new_y][new_x] != 'E'
		&& game->map.map[new_y][new_x] != 'T')
		update_player_position(game, new_x, new_y);
	else if (game->map.map[new_y][new_x] != '1' && game->exit.is_open)
		update_player_position(game, new_x, new_y);
	move_ennemies(game);
	check_collision_ennemies(game);
	return (0);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map.map[game->player.y][game->player.x] = '0';
	game->player.x = new_x;
	game->player.y = new_y;
	game->map.map[new_y][new_x] = 'P';
	draw_map(game);
	collect_collectibles(game);
	check_collision_ennemies(game);
	player_win(game);
}
//Ft pour mes assets score, a retravailler.
/*void	display_move_count(t_game *game, int x, int y)
{
	char	*move_str;
	int		i;
	int		position_count;
	int	id;

	move_str = ft_itoa(game->moves_count);
	position_count = 0;
	i = 0;
	if (!move_str)
		return;
	if (game->moves_count)
	{
		mlx_put_image_to_window(game->window.mlx, game->window.win,
			game->assets.score_img[0], x + position_count, y);
	}
	position_count += 64;
	while (move_str[i] && i < 3)
	{
		id = move_str[i] -'0';
		if (id >= 0 && id <= 9)
		{	
			if (move_str[i] >= '0' && move_str[i] <= '9')
			{
				mlx_put_image_to_window(game->window.mlx, game->window.win, 
					game->assets.score_img[id],
					x + position_count, y);
				position_count += 64;
			}
		}
		i++;
	}
	free(move_str);
}*/
