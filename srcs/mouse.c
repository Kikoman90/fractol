/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:30:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/15 14:28:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mouse(int button, int x, int y, t_mlx *mlx)
{
	if ((button == 1 || button == 5) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		MINX /= 2;
		MINY /= 2;
		MAXX /= 2;
		MAXY /= 2;
	}
	else if ((button == 2 || button == 4) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		MINX *= 2;
		MINY *= 2;
		MAXX *= 2;
		MAXY *= 2;
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
