/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:03:45 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/16 11:13:26 by lduflot          ###   ########.fr       */
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

//load image asset, struct des assets, pe add structure du game avec mlx ? 
void	create_asset(t_assets *assets)
{
	int	img_longeur;
	int	img_hauteur;

	assets->wall_img = mlx_xpm_file_to_image(mlx, &img_longueur, &img_hauteur);

}

void	map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(game->map[y]);
	{
		x=0;
		while(game->map[y][x])
		{
			if(game->map[y][x] == '1')
				mlx_put_image_to_window( );
			else if(game->map[y][x] == '0')
				mlx_put_image_to_window( );
			else if(game->map[y][x] == 'P')
				mlx_put_image_to_window();
			else if(game->map[y][x] == 'E')
				mlx_put_image_to_window();
			else if(game->map[y][x] == 'C')
				mlx_put_image_to_window();
			x++;
		}
		y++;
	}
}

//fonction pour trouver le keycode de la souris
/*int	mouse_hook(int mousecode)
{
	if (mousecode == )
		 if (mousecode // rajouter cliquer croix )
				exit (0);
	return (0);
}*/
int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int	img_width =32;
	int	img_height = 32;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 400, "test");
//	mlx_pixel_put(mlx, win, 1, 1, 0xFF0000); //je le vois pas
	//img = mlx_new_image(mlx, 1920, 1080);
	mlx_string_put(mlx, win, 200, 200, 0xFF0000, "salut ma chips");
	img = mlx_xpm_file_to_image(mlx, "asset/background/Space_Stars1.xpm", &img_width, &img_height);
	if(!img)
		printf("erreur image");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, key_hook, NULL);
	//mlx_mouse_hook(win, mouse_hook, NULL);
	//mlx_mouse_get_pos(mlx, win, x, y);
	mlx_loop(mlx);
	
	return(0);
}
