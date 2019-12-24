/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:46:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/24 08:35:28 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

int		julia(t_coord x, t_coord y, int max)
{
	int				i;
	t_coord			xtmp;
	t_coord			xsq;
	t_coord			ysq;
	static t_coord	cx = -0.835;
	static t_coord	cy = -0.2321;
	const t_coord	radius = 5 * cbrt(cx * cx + cy * cy);
	const t_coord	sqradius = pow(radius, 2.0);

	x = x * radius / 2;
	y = y * radius / 2;
	i = 0;
	xsq = x * x;
	ysq = y * y;
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
