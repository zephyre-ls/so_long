/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:34:49 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/23 14:45:33 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Manque à check : si player débute entouré de mur; si collectible sont entouré de mur, si exit est entouré de mur == si un des cas si dessus est détecté = error

/*int	check_way_valid(t_game *game)
{



	
}*/
//usuless parce que check map s'occupe déjà de verifier cela si il y a du vide ce n'est pas considéré comme un 1 donc carte invalide 
/*int	check_map_rectangle(t_game *game)
{
	int	y = 0;
	int	x = 0;
	int	line_size = 0;

	while(game->map.map[0][line_size])
		line_size++;
	while(y < game->map.longeur)
	{
		x = 0;
		while(game->map.map[y][x])
			x++;
	if (x != line_size)
			return (0);
	y++;
	}
	return (1);
}*/

int	check_map_wall(t_game *game)
{
	int	y = 0;
	int	x = 0;

	while(x < game->map.largeur)
	{
		printf("Première ligne : '%s'\n", game->map.map[0]);
		if(game->map.map[0][x] != '1' || game->map.map[game->map.longeur-1][x] !=  '1')
		{
			printf("la carte doit être entouré de 1/murs\n");
			printf("Problème détecté à y = %d, x = %d, valeur : %c\n", y, x, game->map.map[y][x]);
			return (0);
		}
		x++;
	}
	while(y < game->map.longeur)
	{
		if (game->map.map[y][0] != '1' || game->map.map[y][game->map.largeur-1] != '1')
		{
			printf("la carte doit être entouré de 1/murs\n");
			printf("Problème détecté à y = %d, x = %d, valeur : %c\n", y, x, game->map.map[y][x]);
			return (0);
		}
		y++;
	}
	return (1);
}

