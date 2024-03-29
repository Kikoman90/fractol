/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:34:45 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/15 17:54:46 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_reset(t_mlx *mlx)
{
	mlx->f->cr = -1.1380;
	mlx->f->ci = 0.2403;
	mlx->f->pr = 0.0;
	mlx->f->pi = 0.0;
	mlx->f->mx = 0.0;
	mlx->f->my = 0.0;
	mlx->minx = -3.2;
	mlx->miny = -3.2;
	mlx->maxx = 3.4;
	mlx->maxy = 3.4;
	mlx->freq = 0.1;
	mlx->iter = 16.0;
	mlx->color = 2;
}

static void	ft_switch_julia(t_mlx *mlx, double *tab1, double *tab2, int i)
{
	tab1[0] = -0.772691322542185;
	tab2[0] = 0.124281466072787;
	tab1[1] = -0.7927;
	tab2[1] = 0.1609;
	tab1[2] = -1.1380;
	tab2[2] = 0.2403;
	tab1[3] = -0.1225;
	tab2[3] = 0.7449;
	tab1[4] = -0.32;
	tab2[4] = 0.043;
	tab1[5] = -0.0986;
	tab2[5] = -0.65186;
	tab1[6] = -0.3380;
	tab2[6] = -0.6230;
	while (mlx->f->cr != tab1[i] && i < 7)
		i++;
	if (i < 6)
	{
		mlx->f->cr = tab1[i + 1];
		mlx->f->ci = tab2[i + 1];
	}
	else if ((mlx->f->cr = tab1[0]) != 4.0)
		mlx->f->ci = tab2[0];
}

static int	ft_move(int keycode, t_mlx *mlx)
{
	double	c;

	c = ((MAXX - MINX) / WIN_W) * 10;
	if (keycode == 123)
	{
		MINX += c;
		MAXX += c;
	}
	else if (keycode == 124)
	{
		MINX -= c;
		MAXX -= c;
	}
	else if (keycode == 125)
	{
		MINY -= c;
		MAXY -= c;
	}
	else if (keycode == 126)
	{
		MINY += c;
		MAXY += c;
	}
	return (0);
}

static int	key_hook2(int keycode, t_mlx *mlx)
{
	if (keycode == 1)
	{
		ft_reset(mlx);
		if (mlx->f->nb < 3)
			mlx->f->nb++;
		else
			mlx->f->nb = 1;
	}
	else if (keycode == 0)
		mlx_hook(mlx->win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, mlx);
	return (0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	double	tab1[7];
	double	tab2[7];

	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 49 && mlx->f->nb == 1)
		ft_switch_julia(mlx, tab1, tab2, 0);
	else if (keycode == 69)
		mlx->iter = (mlx->iter < 8000) ? mlx->iter * 2 : mlx->iter;
	else if (keycode == 78)
		mlx->iter = (mlx->iter > 2) ? mlx->iter / 2 : mlx->iter;
	else if (keycode == 8)
		mlx->color++;
	else if (keycode == 3)
		mlx->freq = (mlx->freq < 200) ? mlx->freq * 2 : mlx->freq;
	else if (keycode == 2)
		mlx->freq = (mlx->freq > 0.1) ? mlx->freq / 2 : mlx->freq;
	key_hook2(keycode, mlx);
	ft_move(keycode, mlx);
	ft_draw(mlx);
	return (0);
}
