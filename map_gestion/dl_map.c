/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:40:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 08:30:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void dl_map(t_game *game)
{
	int fd;
	char *line;
	int y;

	y = 0;
	fd = open(game->map.name, O_RDONLY);
	if (fd == -1)
		exit_free_failure(game);
	init_game_counters(game);
	game->map.longeur = count_line(game->map.name);
	game->map.map = malloc(sizeof(char *) * (game->map.longeur + 1));
	if (!game->map.map)
	{
		close(fd);
		exit_free_failure(game);
	}
  while ((line = get_next_line(fd)) != NULL)
	{
		if (y == 0)
  		game->map.largeur = ft_strlen(line);
		game->map.map[y] = line;
		y++;
		}
		game->map.map[y] = NULL;
		close(fd);
		check_map_validity(game, fd);
		y = 0;
		while (y < game->map.longeur)
		{
			assignation_line(game, game->map.map[y], y);
			y++;
		}
		check_map_min(game);
		check_map_accessibility(game, fd);
}

int count_line(char *filename)
{
	int fd;
	int lines_count = 0;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
    return (-1);
	line = get_next_line(fd);
	while (line != NULL)
  {
		lines_count++;
		free(line);
		line = get_next_line(fd);
  }
	close(fd);
	return (lines_count);
}

