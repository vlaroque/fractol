/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:41:08 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/14 19:55:38 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

int		mandelbrot(t_coord x, t_coord y, int max)
{
	int				i;
	t_coord			xtmp;
	t_coord			xsq;
	t_coord			ysq;
	t_coord			cx = x;
	t_coord			cy = y;
	const t_coord	radius = 5 * cbrt(cx * cx + cy * cy);
	const t_coord	sqradius = pow(radius, 2.0);

	x = 0;
	y = 0;
	i = 0;
	xsq = 0;
	ysq = 0;
	while (xsq + ysq < sqradius && i < max)
	{
		xtmp = xsq - ysq;
		y = 2 * x * y + cy;
		x = xtmp + cx;
		xsq = x * x;
		ysq = y * y;
		i++;
	}
	if (i == max)
		return (0);
//	if (i > 10)
//		printf("i = %d\n", i);
	return (i);
}
