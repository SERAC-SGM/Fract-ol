/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:52:06 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/03 17:30:57 by lletourn         ###   ########.fr       */
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

//Operations --- 0 : z1 = z1 * z1 + z2
//-------------- 1 : z1 = z1 * 2 * z2
void	calc_complex(t_complex *z1, t_complex *z2, int operation)
{
	t_complex	z_temp;


	if (operation == 0)
	{
		z_temp.x = z1->x * z1->x - z1->y * z1->y + z2->x;
		z_temp.y = 2 * z1->x * z1->y + z2->y;
		z1->x = z_temp.x;
		z1->y = z_temp.y;
	}
	else if (operation == 1)
	{
		z_temp.x = 2 * (z1->x * z2->x - z1->y * z2->y);
		z_temp.y = 2 * (z1->x * z2->y + z1->y * z2->x);
		z1->x = z_temp.x;
		z1->y = z_temp.y;
	}
}

void	compute_mandelbrot(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;
	//double		fractional_count;

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
	//fractional_count = iter - log(log(z.x * z.x + z.y * z.y)) * (1 / log(2));
	monochrome_gradient(data, pixel, iter);
}

void	compute_mandelbrot_derivative(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	t_complex	derivative;
	int			iter;
	double		treshold;

	convert_to_cartesian(data, &pixel, &z0);
	z.x = z0.x;
	z.y = z0.y;
	derivative.x = 1;
	derivative.y = 0;
	iter = 0;
	treshold = 0.00000001;
	while (iter < ITER_MAX)
	{
		if ((derivative.x * derivative.x + derivative.y * derivative.y) < (treshold * treshold))
		{
			pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(255, 255, 255));
			break;
		}
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(0, 0, 0));
			break;
		}
		calc_complex(&derivative, &z, 1);
		calc_complex(&z, &z0, 0);
		iter++;
		pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(175, 175, 175));
	}
}

int	render_mandelbrot(t_data *data)
{
	t_pixel		pixel;

	pixel.y = 0;
	while (pixel.y < WINDOW_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WINDOW_WIDTH)
		{
			compute_mandelbrot(data, pixel);
			pixel.x++;
		}
		pixel.y++;
	}
	return (0);
}
