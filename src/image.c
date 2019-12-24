/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:37:38 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/24 02:12:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"

t_img		*new_img(void *mlx_ptr, int width, int height)
{
	t_img	*idata;

	if (!(idata = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	idata->width = width;
	idata->height = height;
	idata->img_ptr = mlx_new_image(mlx_ptr, width, height);
	idata->pixs = mlx_get_data_addr(idata->img_ptr,
			&(idata->bits_in_pix), &(idata->size_line), &(idata->endian));
	return (idata);
}

int			ft_color_pix(t_img *img, int x, int y, int color)
{
	int			*pix;

	/*dist = y * data->size_line + (x * (data->bits_in_pix / 8));
	dist = dist / 4;
*/	pix = (int *)img->pixs;
	pix[y * img->width + x] = color;
	return (0);
}
