/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_collectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:48:38 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/22 01:24:31 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAX_COLLECTIBLES)
	{
		printf("entre dans la boucle\n");
		if (game->player.x == game->collectibles[i].x
			&& game->player.y == game->collectibles[i].y
			&& game->collectibles[i].is_collected == 0)
		{
			printf("entre dans le if\n ");
			game->collectibles[i].is_collected = 1;
			printf("nbr collectible collecte %d\n", game->collectible_recup);
			game->collectible_recup++;
			printf("nbr collectible collecte %d\n", game->collectible_recup);
			//game->map.map[game->player.y][game->player.x] = '0';
			////game->map.map[game->player.y][game->player.x] = 'T';
			/*if (i < MAX_MONSTERS)
				game->monsters[i].is_dead = 1;*/
		}
		//break ;
		if (game->collectible_recup == MAX_COLLECTIBLES)
		{
			printf("entre dans is.opem = 1\n");
		printf("nbr collecticles_count = %d\n", game->collectible_recup);
	
			game->exit.is_open = 1;
			game->map.map[game->exit.y][game->exit.x] = 'E';
			mlx_put_image_to_window(game->window.mlx, game->window.win,
						game->assets.exit_open_img, game->exit.x * 64, game->exit.y * 64);

		}
		break ;
	}
	i++;
}
