/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:07:02 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/29 12:37:12 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_asset(t_assets *assets, t_window *mlx)
{
	int	img_l;
	int	img_h;

	assets->wall_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/wall/server.xpm", &img_l, &img_h);
	assets->background_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/background/ciel.xpm", &img_l, &img_h);
	assets->exit_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/exit/ibm5150.xpm", &img_l, &img_h);
	assets->exit_open_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/exit/open.xpm", &img_l, &img_h);
	assets->monster_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/ennemies/monster.xpm", &img_l, &img_h);
	assets->collectibles_img[0] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect1.xpm", &img_l, &img_h);
	assets->collectibles_img[1] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect2.xpm", &img_l, &img_h);
	assets->collectibles_img[2] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect3.xpm", &img_l, &img_h);
	assets->collectibles_img[3] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect4.xpm", &img_l, &img_h);
	assets->collectibles_img[4] = mlx_xpm_file_to_image(mlx->mlx,
			"asset/collectibles/collect5.xpm", &img_l, &img_h);
	assets->code_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/code/code.xpm", &img_l, &img_h);
}

void	create_asset2(t_assets *assets, t_window *mlx)
{
	int	img_l;
	int	img_h;

	assets->player_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/player/player.xpm", &img_l, &img_h);
	assets->player_up_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/player/player_up.xpm", &img_l, &img_h);
	assets->player_down_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/player/player_down.xpm", &img_l, &img_h);
	assets->player_left_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/player/player_left.xpm", &img_l, &img_h);
	assets->player_right_img = mlx_xpm_file_to_image(mlx->mlx,
			"asset/player/player_right.xpm", &img_l, &img_h);
}

//Fonction gestion_tuiles.
void	check_map_min(t_game *game)
{
	if (game->collectible_count <= 0)
	{
		write(2, "Erreur: Le nombre de collectibles doit être > 0\n", 50);
		exit_free_failure(game);
	}
	if (game->monster_count > MAX_MONSTERS)
	{
		write(2, "Erreur: Nbr monstres dépasse maximum autorisé\n", 49);
		exit_free_failure(game);
	}
	if (game->player.player_count != 1)
	{
		write(2, "Erreur: Le nombre de player doit être = 1\n", 43);
		exit_free_failure(game);
	}
	if (game->exit.exit_count != 1)
	{
		write(2, "Erreur: Le nombre de sortie doit être = 1\n", 44);
		exit_free_failure(game);
	}
}
