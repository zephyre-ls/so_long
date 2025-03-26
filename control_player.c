/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:01:10 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/26 02:19:45 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	move_player(keycode, game);
	return (0);
}

/*void	display_move_count(t_game *game)
{
	char *move_str = ft_itoa(game->moves_count);

	mlx_string_put(game->window.mlx, game->window.win, 80, 800, 0xFFFFFF, "Pas:");
	mlx_string_put(game->window.mlx, game->window.win, 80, 600, 0xFFFFFF, move_str);
	free(move_str);
}*/



int step_count = 0;

// Fonction pour incrémenter les pas
void increment_steps() {
    step_count++;
    // Redessiner la fenêtre pour mettre à jour le nombre de pas
    mlx_clear_window(mlx, win);  // Efface la fenêtre
    draw_step_count(mlx, win, step_count, 10, 10);  // Affiche le nombre de pas à la position (10,10)
}
//METTRE EN PLACE UN DISPLAY SUR LES WALL AVEC MES ASSETS SCORE 
void	control_player(int keycode, int *new_x, int *new_y, t_game *game)
{
	//if (game->map.map[*new_x][*new_y] != '1')
	//rajouter un if mouvement valide (si ne va pas dans le mur compte sinon ne compte pas)
	if (keycode == game->control.up_w || keycode == game->control.up_z || keycode == game->control.arrow_up)
	{
	//	if (game->map.map[*new_x][*new_y - 1] != '1')
	//	{
			(*new_y)--;
			game->assets.player_img = game->assets.player_up_img;
			game->moves_count++;
			printf("Pas n°%d\n", game->moves_count);
			display_move_count(game);
	//	}
	}
	else if (keycode == game->control.down || keycode == game->control.arrow_down)
	{
		//if (game->map.map[*new_x][*new_y +1] != '1')
		//{
			(*new_y)++;
			game->assets.player_img = game->assets.player_down_img;
			game->moves_count++;
			printf("Pas n°%d\n", game->moves_count);
			display_move_count(game);
		//}
	}
else if (keycode == game->control.right || keycode == game->control.arrow_right)
	{
		if (game->map.map[*new_x+1][*new_y] != '1')
		{
			(*new_x)++;
			game->assets.player_img = game->assets.player_right_img;
			game->moves_count++;
			printf("Pas n°%d\n", game->moves_count);
			display_move_count(game);
		}
	}
	else if (keycode == game->control.left_a || keycode == game->control.left_q || keycode == game->control.arrow_left)
	{
		if (game->map.map[*new_x-1][*new_y] != '1')
		{
			(*new_x)--;
			game->assets.player_img = game->assets.player_left_img;
			game->moves_count++;
			printf("Pas n°%d\n", game->moves_count);
			display_move_count(game);
		}
	}
	
	else if (keycode == game->control.reset)
		reset_game(game);
	else if (keycode == game->control.quit)
		exit_free(game);    
//	game->assets.player_img = game->assets.player_start_img;
}

int move_player(int keycode, t_game *game)
{
	int new_x = game->player.x;
	int new_y = game->player.y;
	
	control_player(keycode, &new_x, &new_y, game);
//	mlx_clear_window(game->window.mlx, game->window.win);

  if (game->map.map[new_y][new_x] != '1' && game->map.map[new_y][new_x] != 'E' && game->map.map[new_y][new_x] != 'T')
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
