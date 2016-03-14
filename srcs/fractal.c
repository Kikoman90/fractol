/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:46:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/14 16:00:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_instructions(void)
{
	ft_putendl("--- INSTRUCTIONS ---");
	ft_putendl("left mouse : zoom in");
	ft_putendl("right mouse : zoom out");
	ft_putendl("+ : increase iterations");
	ft_putendl("- : decrease iterations");
	ft_putendl("< ^ > v : move");
	ft_putendl("C : change color");
	ft_putendl("F : increase frequency");
	ft_putendl("D : decrease frequency");
	ft_putendl("S : switch fractals");
	ft_putendl("SPC : switch Julia parameters");
	ft_putendl("ESC : close");
	return (0);
}

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

static int	ft_tricorn(t_mlx *mlx, int x, int y)
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
		f->pi = -2 * f->pi * tmp + f->ci;
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
				color = ft_color(ft_tricorn(mlx, x, y), mlx);
			put_pixel(mlx->f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->f->img, 0, 0);
	return (0);
}
