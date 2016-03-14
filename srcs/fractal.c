/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:46:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/14 13:23:58 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_julia(t_mlx *mlx, int x, int y)
{
	t_f		*f;
	int		i;
	double	tmp;

	f = mlx->f;
	i = -1;
	f->pr = -2.2 + ((x * 4.4) / WIN_W);
	f->pi = -2.2 + ((y * 4.4) / WIN_H);
	while (++i < mlx->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

static int	ft_mandelbrot(t_mlx *mlx, int x, int y)
{
	t_f		*f;
	int		i;
	double	tmp;

	f = mlx->f;
	i = -1;
	f->pr = 0;
	f->pi = 0;
	f->cr = -2.2 + ((x * 4.4) / WIN_W);
	f->ci = -2.2 + ((y * 4.4) / WIN_H);
	while (++i < mlx->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int			ft_draw(t_mlx *mlx)
{
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (mlx->f->nb == 1)
				color = ft_color(ft_julia(mlx, x, y), mlx);
			else if (mlx->f->nb == 2)
				color = ft_color(ft_mandelbrot(mlx, x, y), mlx);
			else
				color = 20;
			put_pixel(mlx->f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->f->img, 0, 0);
	return (0);
}
