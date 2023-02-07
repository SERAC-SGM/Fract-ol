/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:32:52 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/07 17:23:48 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	monochrome_gradient(t_data *data, t_pixel pixel, double n)
{
	double	x;

	x = n * 255 / ITER_MAX;
	pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(x, x, x));
}

void	color1(double n, int *r, int *g, int *b)
{
	double	t;

	t = n / ITER_MAX;
	*r = (int)(9 * (1 - t) * t * t * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void	color2(double n, int *r, int *g, int *b)
{
	double	t;

	t = n / ITER_MAX;
	*r = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(9 * (1 - t) * t * t * t * 255);
}

void	change_color(t_data *data)
{
	if (data->color_function == &color1)
		data->color_function = &color2;
	else
		data->color_function = &color1;
}

void	display_color(t_data *data, t_pixel pixel, double n)
{	
	int	r;
	int	g;
	int	b;
	int	color;

	if (n > ITER_MAX)
		color = encode_rgb(0, 0, 0);
	else
	{
		data->color_function(n, &r, &g, &b);
		color = encode_rgb(r, g, b);
	}
	pixel_put_in_image(&data->image, pixel.x, pixel.y, color);
}
