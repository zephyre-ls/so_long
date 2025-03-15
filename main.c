/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:45 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/15 16:52:09 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "test");
	mlx_pixel_put(mlx, win, 100, 100, 0xFF0000); //je le vois pas
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "salut ma chips");

	mlx_loop(mlx);
	return(0);
}
