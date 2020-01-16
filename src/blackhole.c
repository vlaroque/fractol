/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackhole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 05:10:16 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/16 12:47:56 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

/*
**
** ^ 
*/

int		count = 0;

int		flood_fill(t_data *data, int x, int y)
{
	count++;
//	printf("lol %d %d %d\n", x, y, count);
//	if (count > 100)
//		exit(0);
	if (x < 0 || x >= IMG_W || y < 0 || y >= IMG_H)
	{
		printf("     border pb\n");
		return (0);
	}
	printf("content = %d\n", data->matrice[y * IMG_W + x]);
	if (data->matrice[y * IMG_W + x] == -1)
	{
		printf("     already transformed\n");
		return (0);
	}
	if (data->matrice[y * IMG_W + x] > 0)
	{
		printf("     occupied\n");
		return (0);
	}
	if (data->matrice[y * IMG_W + x] == -2 || data->matrice[y * IMG_W + x] == 0)
	{
		printf("     transformation\n");
		data->matrice[y * IMG_W + x] = -1;
	}
	printf(">>> end and childs %d %d %d\n", x, y, count);
	printf("   NORTH\n");
	flood_fill(data, x, y - 1);
	printf("   EAST\n");
	flood_fill(data, x + 1, y);
	printf("   SOUTH\n");
	flood_fill(data, x, y + 1);
	printf("   WEST\n");
	flood_fill(data, x - 1, y);

	printf("   NO MORE\n");
	return (0);
}

t_point point(int x, int y)
{
	t_point pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

int		blackhole(t_data *data, t_point init, t_point pt, int dir)
{
	int i;
	int	res;
	int cnt;

//	count++;
//	cnt = count;
	i = 1;
	res = 0;
	if (pt.x < 0 || pt.x >= IMG_W || pt.y < 0 || pt.y >= IMG_H)
		return (0);
	if (data->matrice[pt.y * IMG_W + pt.x] == 0)
	{
		data->matrice[pt.y * IMG_W + pt.x] = (*(data->fract))(data->x_or
				+ (pt.x * data->pix_off), data->y_or + (pt.y * data->pix_off),
				100);
	}
	else if (dir)
		return (0);
	if (data->matrice[pt.y * IMG_W + pt.x] != -2)
		return (0);
	if (dir && ((pt.x == init.x) && (pt.y == init.y)))
		return (1);
//	printf("blackholded before while %d %d %d\n", pt.x, pt.y, cnt);
	while (i < 4)
	{
		if (i + dir % 4 == 2)
			res = blackhole(data, init, point(pt.x + 1, pt.y), 4);
		else if (i + dir % 4 == 3)
			res = blackhole(data, init, point(pt.x, pt.y - 1), 1);
		else if (i + dir % 4 == 0)
			res = blackhole(data, init, point(pt.x - 1, pt.y), 2);
		else if (i + dir % 4 == 1)
			res = blackhole(data, init, point(pt.x, pt.y + 1), 3);
		if (res)
			return (1);
		i++;
	}
	return (0);
}
