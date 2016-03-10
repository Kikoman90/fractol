/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:14:09 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/10 20:44:49 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIN_W 800
# define WIN_H 800

typedef struct	t_f
{
	void		*img;
	double		pr;
	double		pi;
	double		cr;
	double		ci;
	int			bpp;
	int			endian;
	int			size_line;
	char		*d;
}				t_f;

typedef struct	s_mlx
{
	struct t_f	*f;
	void		*mlx;
	void		*win;
	double		iter;
	double		freq;
	int			color;
}				t_mlx;

#endif
