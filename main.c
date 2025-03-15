/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:45 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/15 19:35:22 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//fonction pour trouver le keycode des touches
//Echap = 65307, Z=122, Q=113, S = 115, D=100, Space = 32
int	key_hook(int keycode)
{
	printf("le keycode est: %d\n", keycode);
	if (keycode == 65307) //press echap la fenetre se ferme
			exit (0);
	return(0);
}
//fonction pour trouver le keycode de la souris
/*int	mouse_hook(int button)
{
	?
}*/
int	main(void)
{
	void	*mlx;
	void	*win;
	//void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "test");
	mlx_pixel_put(mlx, win, 1, 1, 0xFF0000); //je le vois pas
	//img = mlx_new_image(mlx, 1920, 1080);
	mlx_string_put(mlx, win, 200, 200, 0xFF0000, "salut ma chips");
	mlx_key_hook(win, key_hook, NULL);

	mlx_loop(mlx);
	
	return(0);
}
