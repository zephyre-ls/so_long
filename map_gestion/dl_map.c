/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:40:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/29 12:38:41 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Erreur ouverture fichier\n", 26);
		exit(EXIT_FAILURE);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	init_game_counters(t_game *game)
{
	game->monster_count = 0;
	game->collectible_count = 0;
	game->moves_count = 0;
	game->score.s_count = 0;
	game->player.player_count = 0;
	game->exit.exit_count = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->exit.x = -1;
	game->exit.y = -1;
}

void	init_variable_game(t_game *game, int fd)
{
	int	y;

	init_game_counters(game);
	game->map.longeur = count_line(game->map.name);
	game->map.map = malloc(sizeof(char *) * (game->map.longeur + 1));
	if (!game->map.map)
	{
		close(fd);
		exit_free_failure(game);
	}
	y = 0;
	while (y < game->map.longeur)
	{
		game->map.map[y] = NULL;
		y++;
	}
	game->map.map[y] = NULL;
}

void	read_map_line(t_game *game, int fd)
{
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (y == 0)
			game->map.largeur = ft_strlen(line);
		game->map.map[y] = line;
		assignation_line(game, line, y);
		y++;
		line = get_next_line(fd);
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
		write(2, "Erreur ouverture fichier\n", 26);
		exit_free_failure(game);
	}
	init_variable_game(game, fd);
	read_map_line(game, fd);
	check_map_validity(game, fd);
	check_map_min(game);
	check_map_accessibility(game, fd);
	close(fd);
}
