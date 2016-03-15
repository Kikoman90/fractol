/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:30:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/15 17:26:52 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mouse(int button, int x, int y, t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = MAXX - MINX;
	dy = MAXY - MINY;
	mlx->f->mx = ((double)(x) / WIN_W * dx) - dx / 2 + mlx->f->mx;
	mlx->f->my = (double)(y) / WIN_H * dy - dy / 2 + mlx->f->my;
	if ((button == 1 || button == 5) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		MINX = mlx->f->mx - (dx / 1.5) / 2;
		MAXX = mlx->f->mx + (dx / 1.5) / 2;
		MINY = mlx->f->my - (dy / 1.5) / 2;
		MAXY = mlx->f->my + (dy / 1.5) / 2;
	}
	else if ((button == 2 || button == 4) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		MINX = mlx->f->mx - (dx * 1.5) / 2;
		MAXX = mlx->f->mx + (dx * 1.5) / 2;
		MINY = mlx->f->my - (dy * 1.5) / 2;
		MAXY = mlx->f->my + (dy * 1.5) / 2;
	}
	return (ft_draw(mlx));
}

int			ft_motion(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && mlx->f->nb == 1)
	{
		mlx->f->cr = MINX + ((x * MAXX) / WIN_W);
		mlx->f->ci = MINY + ((y * MAXY) / WIN_H);
	}
	return (ft_draw(mlx));
}
