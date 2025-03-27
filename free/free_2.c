/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:20:07 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/27 15:31:22 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_free(t_game *game)
{
	free_exit(game);
	exit (0);
}

void	exit_free_failure(t_game *game)
{
	free_exit(game);
	exit (EXIT_FAILURE);
}

int	close_window(t_game *game)
{
	exit_free(game);
	return (0);
}
