/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 21:09:30 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/16 14:10:24 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

int		matrix_erase(t_data *data)
{
	int		i;

	i = 0;
	while(i < IMG_W * IMG_H)
		data->matrice[i++] = 0;
	return (0);
}


int		matrix_to_img(t_data *data)
{
	int		i;
	int		*pix;

	i = 0;
	pix = (int *)data->imgdata->pixs;
	while(i < IMG_W * IMG_H)
	{
		if (data->matrice[i] <= 0)
			pix[i] = 0x0;
		else
			pix[i] = 0x103 * data->matrice[i];
		i++;
	}
	return (0);
}

int		fill_matrix(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < IMG_H)
	{
		x = 0;
		while (x < IMG_W)
		{
			if (data->matrice[y * IMG_W + x] == -1)
				;
			else if (data->matrice[y * IMG_W + x] == 0)
			{
				data->matrice[y * IMG_W + x] = (*(data->fract))(data->x_or
						+ (x * data->pix_off), data->y_or + (y * data->pix_off), 100);
				if (data->matrice[y * IMG_W + x] == -2)
				{
					data->matrice[y * IMG_W + x] = 0;
					printf("   >>> new %d %d\n", x, y);
//					blackhole(data, point(x, y), point(x, y), 0);
				//	printf("blackhole done\n");
//					flood_fill(data, x, y);
				//	printf("flood fill done\n");
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		show_matrix(t_data *data)
{
	matrix_erase(data);
	fill_matrix(data);
	matrix_to_img(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgdata->img_ptr,
			WIN_W / 2 - IMG_W / 2, WIN_H / 2 - IMG_H / 2);
	return (0);
}
