/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:14:09 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/07 17:50:40 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>

typedef struct	s_img
{
	void		*img;
	int			color;
	int			bpp;
	int			endian;
	int			size_line;
	char		*d;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
}				t_mlx;

#endif
