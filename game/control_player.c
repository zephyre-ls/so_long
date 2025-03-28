/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:01:10 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/28 01:33:20 by lduflot          ###   ########.fr       */
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
	if (game->exit.is_open)
		gestion_mouvement_e_open(keycode, new_x, new_y, game);
	else
		gestion_mouvement_e_close(keycode, new_x, new_y, game);
	if (keycode == game->control.quit)
		exit_free(game);
	if (*new_x != x || *new_y != y)
	{
		game->moves_count++;
		game->score.s_count++;
		write(1, "Score : ", 8);
		ft_putnbr_fd(game->moves_count, 1);
		write(1, "\n", 1);
		display_move_count(game, 10, 780);
	}
}

int	move_player(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	control_player(keycode, &new_x, &new_y, game);
	if (game->map.map[new_y][new_x] != '1')
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
