/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:22:32 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/25 22:26:42 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
char **map_copy(t_game *game)
{
    char **copy;
    int line;

  copy = malloc((game->map.longeur + 1) * sizeof(char *));
  if (!copy)
    return (NULL);

  line = 0;
  while (line < game->map.longeur)
  {
    copy[line] = malloc((game->map.largeur + 1) * sizeof(char));
    if (!copy[line])
    {
      while (line >= 0)
        free(copy[line]);
			line--;
    free(copy);
    return (NULL);
    }
    ft_memcopy(copy[line], game->map.map[line], game->map.largeur + 1);
		line++;
	}
  copy[game->map.longeur] = NULL;
  return copy;
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
