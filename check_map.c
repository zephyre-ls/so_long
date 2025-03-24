/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:34:49 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/24 23:21:51 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Manque à check : si player débute entouré de mur; si collectible sont entouré de mur, si exit est entouré de mur == si un des cas si dessus est détecté = error


void	*ft_memcopy(char *dest, char *src, size_t n)
{
	size_t		i;

	i = 0;
	if (src == NULL || dest == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
//copie la carte du jeu
// Copie la carte du jeu
char **map_copy(t_game *game)
{
    char **copy;
    int line;

  copy = malloc((game->map.largeur + 1) * sizeof(char *));
  if (!copy)
    return (NULL);

  line = -1;
  while (line < game->map.largeur)
  {
    copy[line] = malloc(game->map.longeur * sizeof(char));
    if (!copy[line])
    {
      while (line >= 0)
        free(copy[line]);
			line--;
    free(copy);
    return (NULL);
    }
		if (game->map.map[line] != NULL)
    	ft_memcopy(copy[line], game->map.map[line], game->map.longeur);
    }
		line++;
    copy[line] = NULL;
    return copy;
}


int	flood_fill(char **map, int current_row, int current_col, int map_longeur, int map_largeur)
{
	int	elem_collected;

	if (current_row < 0 || current_row >= map_longeur || current_col < 0 || current_col >= map_largeur)
    return 0;
	if (map[current_row][current_col] == '1')
		return (0);
	elem_collected = 0;
	if (map[current_row][current_col] == 'C' || map[current_row][current_col] == 'E')
		elem_collected += 1;
	map[current_row][current_col] = '1';
	elem_collected += flood_fill(map, current_row, current_col - 1, map_longeur, map_largeur); //gauche
	elem_collected += flood_fill(map, current_row, current_col + 1, map_longeur, map_largeur); //droite
	elem_collected += flood_fill(map, current_row - 1, current_col, map_longeur, map_largeur); //haut
	elem_collected += flood_fill(map, current_row + 1, current_col, map_longeur, map_largeur); //bas
	return (elem_collected);
}


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

//Flood_fill pour voir si tous les chemins sont accessibles par le P


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
				perror("Erreur: caractere inconnu dans la carte.");
				exit_free_failure(game);
			}
			j++;
		}
		i++;
	}
}

int	check_map_wall(t_game *game)
{
	int	y = 0;
	int	x = 0;

	while(x < game->map.largeur)
	{
		if(game->map.map[0][x] != '1' || game->map.map[game->map.longeur-1][x] !=  '1')
			return (0);
		x++;
	}
	while(y < game->map.longeur)
	{
		if (game->map.map[y][0] != '1' || game->map.map[y][game->map.largeur-1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	check_name(char *name)
{
	int	len;
	int	compar;

	len = 0;
	while(name[len])
		len++;
	if (len < 4)
	{
		perror("Type de fichier accepte : .ber\n");
		exit (EXIT_FAILURE);
	}
	compar = ft_strcmp(name + (len - 4), ".ber");
	if (compar != 0)
	{
		perror("Type de fichier accepte : .ber\n");
		exit (EXIT_FAILURE);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
