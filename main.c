/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:39:33 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/10 20:28:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_julia(t_mlx *mlx, int x, int y)
{
	t_f		*f;
	int		i;
	double	tmp;

	f = mlx->f;
	i = -1;
	f->pr = -2.1 + (x * 4.2 / WIN_W);
	f->pi = -2.1 + (y * 4.2 / WIN_H);
	while (++i < mlx->iter && (f->pr * f->pr + f->pi * f->pi) <= 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int		ft_color(int i, t_mlx *mlx)
{
	int		red;
	int		green;
	int		blue;
	double	co;

	if (i >= mlx->iter)
		return (0);
	co = mlx->freq * (i + 1);
	red = cos(co) * 127 + 128;
	green = cos(co + mlx->color) * 127 + 128;
	blue = cos(co + 2 * mlx->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

void	put_pixel(t_f *f, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (f->bpp / 8) + y * (f->size_line);
	while (i < (f->bpp / 8))
	{
		f->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int		ft_draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx->color = ft_color(ft_julia(mlx, x, y), mlx);
			put_pixel(mlx->f, x, y, mlx->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->f->img, 0, 0);
	return (0);
}

t_f		*init_fract(void)
{
	t_f	*f;

	if (!(f = (t_f *)malloc(sizeof(t_f))))
		return (NULL);
	f->cr = -0.772691322542185;
	f->ci = 0.124281466072787;
	f->pr = 0.0;
	f->pi = 0.0;
	return (f);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->f = init_fract()))
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->f->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "fractol");
	mlx->f->d = mlx_get_data_addr(mlx->f->img, &mlx->f->bpp, &mlx->f->size_line\
				, &mlx->f->endian);
	mlx->freq = 0.1;
	mlx->iter = 70.0;
	mlx->color = 2;
	return (mlx);
}

int		main(void)
{
	t_mlx	*mlx;

	if ((mlx = init_mlx()) != NULL)
	{
		ft_draw(mlx);
		mlx_loop(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}
