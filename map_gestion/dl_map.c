/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:40:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/27 15:08:13 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_variable_game(t_game *game)
{
	game->monster_count = 0;
	game->collectible_count = 0;
	game->moves_count = 0;
	game->score.s_count = 0;
	game->map.map = malloc(sizeof(char *) * 20);
	if (!game->map.map)
	{
		perror("Erreur allocation"),
		exit_free_failure(game);
	}
}

void	read_map_line(t_game *game, int fd)
{
	int		y;
	char	*line;

	y = 0;
	while ((line = get_next_line(fd)))
	{
		if (y == 0)
			game->map.largeur = ft_strlen(line);
		game->map.map[y] = line;
		assignation_line(game, line, y);
		y++;
	}
	game->map.longeur = y;
	game->map.map[y] = NULL;
}

void	dl_map(t_game *game)
{
	int		fd;

	fd = open(game->map.name, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur ouverture fichier");
		exit_free_failure(game);
	}
	init_variable_game(game);
	read_map_line(game, fd);
	check_map_validity(game, fd);
	check_map_accessibility(game, fd);
	close(fd);
}

void	check_map_validity(t_game *game, int fd)
{
	check_chars(game->map.map, game);
	if (!check_map_wall(game))
	{
		perror("Erreur, la carte n'est pas entourée de mur\n");
		close(fd);
		exit_free_failure(game);
	}
}

void	check_map_accessibility(t_game *game, int fd)
{
	t_map	temp_map;

	temp_map.map = map_copy(game);
	if (!temp_map.map)
	{
		perror("Erreur lors de la création de la copie de la carte\n");
		close(fd);
		exit_free_failure(game);
	}
	temp_map.longeur = game->map.longeur;
	temp_map.largeur = game->map.largeur;
	if (flood_fill(&temp_map, game->player.y, game->player.x)
		!= game->collectible_count + 1)
	{
		perror("Erreur, collectible ou exit non accessible par le player\n");
		close(fd);
		exit_free_failure(game);
	}
	free_map(temp_map.map);
}
