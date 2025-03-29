/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:40:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 00:17:53 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dl_map(t_game *game)
{
	int		fd;

	fd = open(game->map.name, O_RDONLY);
	if (fd == -1)
		exit_free_failure(game);
	init_variable_game(game, fd);
	read_map_line(game, fd);
	check_map_validity(game, fd);
	check_map_min(game);
	check_map_accessibility(game, fd);
	close(fd);
}

int	count_line(char *filename)
{
	int		fd;
	int		lines_count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	lines_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines_count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (lines_count);
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
	//free_map(game->map.map);
}


