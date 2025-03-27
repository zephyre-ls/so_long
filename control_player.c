/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:01:10 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/27 13:50:27 by lduflot          ###   ########.fr       */
/*              e                                                               */
/* ************************************************************************** */

#include "so_long.h"

void	display_move_count(t_game *game, int x, int y)
{
	char	*move_str;

	move_str = ft_itoa(game->moves_count);
	if (!move_str)
		return ;
  mlx_clear_window(game->window.mlx, game->window.win);
	mlx_string_put(game->window.mlx, game->window.win, x, y, 0xFFFFFF, "Score:");
	mlx_string_put(game->window.mlx, game->window.win, x + 50, y, 0xFFFFFF, move_str);
	free(move_str);
}

void	control_player(int keycode, int *new_x, int *new_y, t_game *game)
{
	int	x;
	int	y;

	x = *new_x;
	y = *new_y;

	if (keycode == game->control.up_w || keycode == game->control.up_z || keycode == game->control.arrow_up)
	{
		if (game->map.map[*new_y - 1][*new_x] != '1')
		{
			(*new_y)--;
			game->assets.player_img = game->assets.player_up_img;
		}
	}
	else if (keycode == game->control.down || keycode == game->control.arrow_down)
	{
		if (game->map.map[*new_y + 1][*new_x] != '1')
		{
			(*new_y)++;
			game->assets.player_img = game->assets.player_down_img;
		}
	}
else if (keycode == game->control.right || keycode == game->control.arrow_right)
	{
		if (game->map.map[*new_y][*new_x + 1] != '1')
		{
			(*new_x)++;
			game->assets.player_img = game->assets.player_right_img;
		}
	}
	else if (keycode == game->control.left_a || keycode == game->control.left_q || keycode == game->control.arrow_left)
	{
		if (game->map.map[*new_y][*new_x - 1] != '1')
		{
			(*new_x)--;
			game->assets.player_img = game->assets.player_left_img;
		}
	}
	else if (keycode == game->control.quit)
		exit_free(game);
	if (*new_x != x || *new_y != y)
	{
		game->moves_count++;
		game->score.s_count ++;
		printf("Pas : %d\n", game->moves_count);
		display_move_count(game, 10, 780);
	//	game->assets.player_img = game->assets.player_start_img;
	}
}

int move_player(int keycode, t_game *game)
{
	int new_x = game->player.x;
	int new_y = game->player.y;
	
	control_player(keycode, &new_x, &new_y, game);
  if (game->map.map[new_y][new_x] != '1' && game->map.map[new_y][new_x] != 'E'
		&& game->map.map[new_y][new_x] != 'T' && game->map.map[new_y][new_x] != 'S')
		update_player_position(game, new_x, new_y);
	else if (game->map.map[new_y][new_x] != '1' && game->exit.is_open
			&& game->map.map[new_y][new_x] != 'S')
		update_player_position(game, new_x, new_y);
	move_ennemies(game);
	check_collision_ennemies(game);
	return 0;
}

void update_player_position(t_game *game, int new_x, int new_y)
{
	game->map.map[game->player.y][game->player.x] = '0';
	game->player.x = new_x;
	game->player.y = new_y;
	collect_collectibles(game);
	check_collision_ennemies(game);
	game->map.map[new_y][new_x] = 'P';
	player_win(game);
	draw_map(game);
}

int	cant_move_wall(int new_x, int new_y, t_game *game)
{
	if (game->map.map[new_y][new_x] == '1')
		return (1);
	return (0);
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


