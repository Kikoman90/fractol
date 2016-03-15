/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:30:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/15 12:39:25 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_motion(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && mlx->f->nb == 1)
	{
		mlx->f->cr = MINX + ((x * MAXX) / WIN_W);
		mlx->f->ci = MINY + ((y * MAXY) / WIN_H);
	}
	return (ft_draw(mlx));
}
