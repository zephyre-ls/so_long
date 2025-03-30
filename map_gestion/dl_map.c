/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:40:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 21:10:59 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Ouverture du fichier, lecture, compte, pour malloc.
int	count_line(char *filename)
{
	int		fd;
	int		lines_count;
	char	*line;

	lines_count = 0;
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

//stocke la map dans map.map
void	dl_map(t_game *game)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = open(game->map.name, O_RDONLY);
	if (fd == -1)
		exit_free_failure(game);
	game->map.longeur = count_line(game->map.name);
	game->map.map = malloc(sizeof(char *) * (game->map.longeur + 1));
	if (!game->map.map)
		exit_free_failure(game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (y == 0)
			game->map.largeur = ft_strlen(line);
		game->map.map[y++] = line;
		line = get_next_line(fd);
	}
	game->map.map[y] = NULL;
	close(fd);
	dl_map_check(game, fd);
}

//verification de la map
void	dl_map_check(t_game *game, int fd)
{
	int	y;

	y = 0;
	check_map_validity(game, fd);
	init_game_counters(game);
	while (y < game->map.longeur)
	{
		assignation_line(game, game->map.map[y], y);
		y++;
	}
	check_map_min(game);
	check_map_accessibility(game, fd);
	if (check_collect_acces_block(game))
	{
		write(2, "Erreur : Non acces au premier collectible \n", 44);
		exit_free_failure(game);
	}
}
