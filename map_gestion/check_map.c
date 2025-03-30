/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:34:49 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/30 09:48:22 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_name(char *name)
{
	int	len;
	int	compar;

	len = 0;
	while (name[len])
		len++;
	if (len < 4)
	{
		write(2, "Erreur/ Type de fichier attendu : .ber\n", 40);
		exit (EXIT_FAILURE);
	}
	compar = ft_strcmp(name + (len - 4), ".ber");
	if (compar != 0)
	{
		write(2, "Erreur/ Type de fichier attendu : .ber\n", 40);
		exit (EXIT_FAILURE);
	}
}

int	check_map_rectangle(t_game *game)
{
	int	i;
	int	first_line;
	int	other_line;

	i = 0;
	first_line = ft_strlen(game->map.map[0]);
	while (game->map.map[i])
	{
		other_line = ft_strlen(game->map.map[i]);
		if (first_line != other_line)
		{
			write(2, "Erreur: La map n'est pas rectangulaire\n", 40);
			exit_free_failure(game);
		}
		i++;
	}
	return (0);
}

int	check_map_wall(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (x < game->map.largeur)
	{
		if (game->map.map[0][x] != '1'
			|| game->map.map[game->map.longeur - 1][x] != '1')
			map_wall_error(game);
		x++;
	}
	while (y < game->map.longeur)
	{
		if (game->map.map[y][0] != '1'
			|| game->map.map[y][game->map.largeur - 1] != '1')
			map_wall_error(game);
		y++;
	}
	return (0);
}

void	map_wall_error(t_game *game)
{
	write(2, "Erreur : la carte doit être entourée de mur\n", 47);
	exit_free_failure(game);
}

void	check_chars(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map [i][j] != '1'
			&& map[i][j] != 'P' && map[i][j] != 'E'
			&& map[i][j] != 'C' && map[i][j] != 'T'
			&& map[i][j] != 'M')
			{
				write(2, "Erreur: caractere inconnu détecté\n", 37);
				exit_free_failure(game);
			}
			j++;
		}
		i++;
	}
}
