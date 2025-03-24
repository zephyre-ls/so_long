/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_collectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:48:38 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/24 11:08:30 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	collect_collectibles(t_game *game)
{
	int	i;
	int new_x=game->player.x;
	int	new_y=game->player.y;

	i = 0;
	printf("Début de la fonction, collectible_count = %d\n", game->collectible_count);
	while (i < MAX_COLLECTIBLES)
	{
	printf("entre dans la boucle - Vérification du collectible %d\n", i);
	printf("joueur: (%d, %d) | collectible %d: (%d, %d) | is_collected: %d\n", 
	game->player.x, game->player.y, i,
	game->collectibles[i].x, game->collectibles[i].y,
	game->collectibles[i].is_collected);
	printf("Types -> Joueur (%lu, %lu) | Collectible (%lu, %lu)\n",
    sizeof(game->player.x), sizeof(game->player.y),
    sizeof(game->collectibles[i].x), sizeof(game->collectibles[i].y));

		
		if (game->player.x == game->collectibles[i].x
			&& game->player.y == game->collectibles[i].y
			&& game->collectibles[i].is_collected == 0)
		{
			printf("entre dans le if\n ");
			game->collectibles[i].is_collected = 1;
			printf("nbr collectible collecte %d\n", game->collectible_count);
			game->collectible_count--;
			printf("Collectible ramassé ! Nouveau count: %d\n", game->collectible_count);
			game->map.map[game->player.y][game->player.x] = '0';
			printf("nbr collectible collecte %d\n", game->collectible_count);
			if (i < MAX_MONSTERS)
				game->monsters[i].is_dead = 1;
		}
		//break ;
		if (game->collectible_count == 0)
		{
			printf("entre dans is.opem = 1\n");
		printf("nbr collecticles_count = %d\n", game->collectible_count);
	
			game->exit.is_open = 1;
			game->map.map[game->exit.y][game->exit.x] = 'E';
			mlx_put_image_to_window(game->window.mlx, game->window.win,
						game->assets.exit_open_img, game->exit.x * 64, game->exit.y * 64);

		}
		i++;
	}
}*/ 

void collect_collectibles(t_game *game)
{
	int i = 0;

	while (i < game->collectible_count)
  {
	//	printf("collectible_count : %d, id; %d \n", game->collectible_count, game->collectibles[i].id);
		if (game->collectibles[i].x == game->player.x && game->collectibles[i].y == game->player.y 
			&& !game->collectibles[i].is_collected)
		{
		//	printf("Le joueur est sur le collectible: %d\n", game->collectibles[i].id);
			if (game->collectibles[i].id == game->next_collectible)
			{
				game->collectibles[i].is_collected = 1;
				game->next_collectible++;
			//	printf("Collectible %d récupéré !\n", game->collectibles[i].id);
				if (game->next_collectible == game->collectible_count)
				{
				//		printf("Tous les collectibles collectés, ouverture de la porte\n");
						game->exit.is_open = 1;
					//	printf("Porte avant ouverture: x = %d, y = %d, is_open = %d\n", 
  				//	game->exit.x, game->exit.y, game->exit.is_open);
						game->map.map[game->exit.y][game->exit.x] = 'E';

				}
			}
			else
			{
					write(1, "Mauvais collectible collecte, rejouez.\n", 39);
					exit_free(game);
					game->map.map[game->collectibles[i].y][game->collectibles[i].x] = 'C';
			}
		}
		i++;
  }
	draw_map(game);
}

/*void collect_collectibles(t_game *game)
{
	int new_x = game->player.x;
	int new_y = game->player.y;

	if (game->map.map[new_y][new_x] == 'C')
	{
		game->map.map[new_y][new_x] = '0';
		game->collectible_count--;
int	x = 0;
		int	y = 0;
		printf("%d, %d\n", game->map.largeur, game->map.longeur);
	while (y < game->map.largeur)
		{
  	while (x < game->map.longeur)
			{
				if (game->map.map[y][x] == 'M')
				{
					game->map.map[y][x] = '0';
					game->monster_count--;
					printf("Monstre supprimé ! Nbr restant de monstres : %d\n", game->monster_count);
					return; 
				}
 				x++;
			}
			y++; 
			x = 0;
		}*/
/*		printf("collectible collecté ! Nbr restant: %d\n", game->collectible_count);
		printf("etat de la sortie : %d\n", game->exit.is_open);
		if (game->collectible_count == 0)
		{
			printf("tous les collectibles collectés, ouverture de la porte\n");
			game->exit.is_open = 1;
			printf("Porte avant ouverture: x = %d, y = %d, is_open = %d\n", game->exit.x, game->exit.y, game->exit.is_open);
			game->map.map[game->exit.y][game->exit.x] = 'E';
			//mlx_clear_window(game->window.mlx, game->window.win);
			//mlx_put_image_to_window(game->window.mlx, game->window.win,
			//game->assets.exit_open_img, game->exit.x * 64, game->exit.y * 64);
			//draw_map(game);
		}
	}
}*/

