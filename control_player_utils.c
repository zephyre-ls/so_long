/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:41:50 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/26 17:41:09 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;

	len = ft_len(n);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	if (n == 0)
		dest[0] = '0';
	while (n != 0)
	{
		dest[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (dest);
}

int	key_hook(int keycode, t_game *game)
{
	move_player(keycode, game);
	return (0);
}

void	init_controls(t_game *game)
{
	game->control.up_w = 119;
	game->control.up_z = 122;
	game->control.down = 115;
	game->control.left_a = 97;
	game->control.left_q = 113;
	game->control.right = 100;
	game->control.arrow_up = 65362;
	game->control.arrow_down = 65364;
	game->control.arrow_right = 65363;
	game->control.arrow_left = 65361;
	game->control.quit = 65307;
}
