/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:01:10 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/25 09:54:15 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	move_player(keycode, game);
	return (0);
}

void	init_controls(t_game *game)
{
	game->control.up_w = 119;
	game->control.up_z = 122;
	game->control.down = 115;
	game->control.left_a = 97;
	game->control.left_q = 113;
	game->control.right = 100;
	game->control.arrow_up = 65362;
	game->control.arrow_down = 65364;
	game->control.arrow_right = 65363;
	game->control.arrow_left = 65361;
	game->control.quit = 65307;
	game->control.reset = 114;
}

int	ft_len(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size++;
	}
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;

	len = ft_len(n);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	if (n == 0)
		dest[0] = '0';
	while (n != 0)
	{
		dest[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (dest);
}

void	display_move_count(t_game *game)
{
	char *move_str = ft_itoa(game->moves_count);

	mlx_string_put(game->window.mlx, game->window.win, 80, 800, 0xFFFFFF, "Pas: ");
	mlx_string_put(game->window.mlx, game->window.win, 80, 600, 0xFFFFFF, move_str);
	free(move_str);
}

void	control_player(int keycode, int *new_x, int *new_y, t_game *game)
{
	//if (game->map.map[*new_x][*new_y] != '1')
	//rajouter un if mouvement valide (si ne va pas dans le mur compte sinon ne compte pas)
	if (keycode == game->control.up_w || keycode == game->control.up_z || keycode == game->control.arrow_up)
	{
		//if (game->map.map[*new_x][*new_y - 1] != '1')
		//{
			(*new_y)--;
			game->moves_count++;
			printf("Pas n°%d\n", game->moves_count);
			display_move_count(game);
		//}
	}
	else if (keycode == game->control.down || keycode == game->control.arrow_down)
	{
		(*new_y)++;
		game->moves_count++;
		printf("Pas n°%d\n", game->moves_count);
		display_move_count(game);
	}
else if (keycode == game->control.right || keycode == game->control.arrow_right)
	{
		(*new_x)++;
		game->moves_count++;
		printf("Pas n°%d\n", game->moves_count);
		display_move_count(game);
	}
	else if (keycode == game->control.left_a || keycode == game->control.left_q || keycode == game->control.arrow_left)
	{
		(*new_x)--;
		game->moves_count++;
		printf("Pas n°%d\n", game->moves_count);
		display_move_count(game);
	}
	else if (keycode == game->control.reset)
		reset_game(game);
	else if (keycode == game->control.quit)
		exit_free(game);
}

int move_player(int keycode, t_game *game)
{
	int new_x = game->player.x;
	int new_y = game->player.y;
	
	control_player(keycode, &new_x, &new_y, game);

  if (game->map.map[new_y][new_x] != '1' && game->map.map[new_y][new_x] != 'E' && game->map.map[new_y][new_x] != 'T')
	{	
		//mlx_clear_window(game->window.mlx, game->window.win);
		game->map.map[game->player.y][game->player.x] = '0';
		game->player.x = new_x;
		game->player.y = new_y;
		collect_collectibles(game);
		check_collision_ennemies(game);
		game->map.map[new_y][new_x] = 'P';
		player_win(game);
		draw_map(game);
	}
	else if (game->map.map[new_y][new_x] != '1' && game->exit.is_open)
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
	move_ennemies(game);
	check_collision_ennemies(game);
	return 0;
}

void	reset_game(t_game *game)
{
	dl_map(game);
	create_asset(&game->assets, &game->window);
	draw_map(game);
}

int	cant_move_wall(int new_x, int new_y, t_game *game)
{
	if (game->map.map[new_y][new_x] == '1')
		return (1);
	return (0);
}
