/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:39:33 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/07 19:49:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color(int color)
{
	int	red;
	int	green;
	int	blue;

	red = cos(0.1) * 256;
	green = cos(0.1 + color) * 256;
	blue = cos(0.1 + color + color) * 256;
	return ((red << 16) + (blue << 8) + green);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (img->bpp / 8) + y * (img->size_line);
	while (i < (img->bpp / 8))
	{
		img->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int		main(void)
{
	t_mlx	mlx;
	t_img	img;

	img.color = 2;
	mlx.mlx = mlx_init();
	mlx.height = 800;
	mlx.width = 800;
	img.img = mlx_new_image(mlx.mlx, mlx.height, mlx.width);
	mlx.win = mlx_new_window(mlx.mlx, mlx.height, mlx.width, "fractol");
	img.d = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	//ft_fractal(mlx, img);
	//mlx_key_hook(mlx.win, &ft_key_hook, &mlx);
	//mlx_mouse_hook(mlx.win, &ft_mouse_hook, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
