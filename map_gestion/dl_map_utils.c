/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:24:28 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/29 12:36:34 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_validity(t_game *game, int fd)
{
	if (game->map.longeur == 0 || game->map.largeur == 0
		|| game->map.map == NULL || game->map.map[0] == NULL)
	{
		write(2, "Erreur : La carte est vide\n", 28);
		close(fd);
		exit_free_failure(game);
	}
	check_chars(game->map.map, game);
	if (!check_map_wall(game))
	{
		write(2, "Erreur, la carte n'est pas entourée de mur\n", 45);
		exit_free_failure(game);
	}
	close (fd);
}

void	check_map_accessibility(t_game *game, int fd)
{
	t_map	temp_map;

	if (game->player.x < 0 || game->player.x >= game->map.largeur
		|| game->player.y < 0 || game->player.y >= game->map.longeur)
	{
		close(fd);
		exit_free_failure(game);
	}
	temp_map.map = map_copy(game);
	if (!temp_map.map)
	{
		close(fd);
		exit_free_failure(game);
	}
	temp_map.longeur = game->map.longeur;
	temp_map.largeur = game->map.largeur;
	if (flood_fill(&temp_map, game->player.y, game->player.x)
		!= game->collectible_count + 1)
	{
		write(2, "Erreur, C ou E non accessible par le player.\n", 46);
		free_map(temp_map.map);
		close(fd);
		exit_free_failure(game);
	}
	free_map(temp_map.map);
}
