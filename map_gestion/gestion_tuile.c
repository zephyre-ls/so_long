/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_tuile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:32 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 09:07:37 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	assignation_line(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'P')
			gestion_player(game, x, y);
		else if (line[x] == 'E')
			gestion_exit(game, x, y);
		else if (line[x] == 'M')
			gestion_monster(game, x, y);
		else if (line[x] == 'C')
			gestion_collectible(game, x, y);
		x++;
	}
}

void	gestion_player(t_game *game, int x, int y)
{
	int	count_p = 0;

	if (count_p > 1)
	{
		write(2, "Erreur : Mode multi non pris en charge\n", 39);
		exit_free_failure(game);
	}
	game->player.x = x;
	game->player.y = y;
	game->start_position.x = x;
	game->start_position.y = y;
	game->player.player_count++;
	count_p++;
}

void	gestion_exit(t_game *game, int x, int y)
{
	int	count_e = 0;

	if (count_e > 1)
	{
		write(2, "Erreur : Une seule sortie autorisée\n", 38);
		exit_free_failure(game);
	}
	game->exit.x = x;
	game->exit.y = y;
	game->exit.is_open = 0;
	game->exit.exit_count++;
	count_e++;
}

void	gestion_monster(t_game *game, int x, int y)
{
	if (game->monster_count >= MAX_MONSTERS)
	{
		write(2, "Erreur: Maximum 4 ennemies\n", 28);
		exit_free_failure(game);
	}
	else
	{
		game->monsters[game->monster_count].x = x;
		game->monsters[game->monster_count].y = y;
		game->monster_count++;
	}
}

void	gestion_collectible(t_game *game, int x, int y)
{
	if (game->collectible_count >= MAX_COLLECTIBLES)
	{
		write(2, "Erreur: Nbr collectibles autorisé dépasse le maximum\n", 56);
		exit_free_failure(game);
	}
	else
	{
		game->collectibles[game->collectible_count].x = x;
		game->collectibles[game->collectible_count].y = y;
		game->collectibles[game->collectible_count].id
			= game->collectible_count;
		game->collectibles[game->collectible_count].is_collected = 0;
		game->next_collectible = 0;
		game->collectible_count++;
	}
}
