/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:34:45 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/14 16:05:00 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	while (mlx->f->cr != tab1[i])
		i++;
	if (i < 6)
	{
		mlx->f->cr = tab1[i + 1];
		mlx->f->ci = tab2[i + 1];
	}
	else if ((mlx->f->cr = tab1[0]) != 4.0)
		mlx->f->ci = tab2[0];
}

int			key_hook(int keycode, t_mlx *mlx)
{
	double	tab1[7];
	double	tab2[7];

	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 53)
		exit(0);
	if (keycode == 49 && mlx->f->nb == 1)
		ft_switch_julia(mlx, tab1, tab2, 0);
	ft_draw(mlx);
	return (0);
}