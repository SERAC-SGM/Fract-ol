/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:52:06 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/05 16:34:11 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	set_zero(t_complex *z)
{
	z->x = 0;
	z->y = 0;
}

void	set_complex(t_complex *z, double n1, double n2)
{
	z->x = n1;
	z->y = n2;
}

void	set_cartesian(t_data *data, t_pixel *pixel, t_complex *z)
{
	z->x = ((float)pixel->x * (data->xmax - data->xmin)
			/ (float)(WINDOW_WIDTH) + data->xmin);
	z->y = ((float)pixel->y * (data->ymax - data->ymin)
			/ (float)(WINDOW_HEIGHT) + data->ymin);
}

int	render_each_pixel(t_data *data)
{
	t_pixel		pixel;

	pixel.y = 0;
	while (pixel.y < WINDOW_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WINDOW_WIDTH)
		{
			data->compute_set(data, pixel);
			pixel.x++;
		}
		pixel.y++;
	}
	return (0);
}
