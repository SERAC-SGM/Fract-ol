/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:52:06 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 14:55:54 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	set_zero(t_complex *z)
{
	z->x = 0;
	z->y = 0;
}

void	convert_to_cartesian(t_data *data, t_pixel *pixel, t_complex *z)
{
	z->x = ((float)pixel->x * (data->xmax - data->xmin)
			/ (float)(WINDOW_WIDTH) + data->xmin);
	z->y = ((float)pixel->y * (data->ymax - data->ymin)
			/ (float)(WINDOW_HEIGHT) + data->ymin);
}

void	compute_mandelbrot(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;

	set_zero(&z);
	convert_to_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	data->display_set(data, pixel, iter);
}

void	compute_mandelbrot_fractional(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;
	double		fractional_count;

	set_zero(&z);
	convert_to_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	fractional_count = iter - log(log(z.x * z.x + z.y * z.y)) * (1 / log(2));
	data->display_set(data, pixel, fractional_count);
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
