/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:32:52 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 18:37:13 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	linear_gradient(t_data *data, t_pixel pixel, double n)
{
	int	r;
	int	g;
	int	b;

	r = n * 255 / ITER_MAX;
	g = 0;
	b = 255 - r;
	pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(r, g, b));
}

void	monochrome_gradient(t_data *data, t_pixel pixel, double n)
{
	double	x;

	x = n * 255 / ITER_MAX;
	pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(x, x, x));
}

void	monochrome_gradient_reverse(t_data *data, t_pixel pixel, double n)
{
	double	x;

	x = 255 - (n * 255 / ITER_MAX);
	pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(x, x, x));
}

void	psychedelic_bnw(t_data *data, t_pixel pixel, double n)
{
	if ((int)n % 2 != 0)
		pixel_put_in_image(&data->image, pixel.x, pixel.y,
			encode_rgb(255, 255, 255));
	else
		pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(0, 0, 0));

}

void	psychedelic1(t_data *data, t_pixel pixel, double n)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * sin(n));
	g = (int)(255 * sin(n + 2 * M_PI / 3));
	b = (int)(255 * sin(n + 10 * M_PI / 8));

	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(r, g, b));
}

void	pretty1(t_data *data, t_pixel pixel, double n)
{
	int	r;
	int	g;
	int	b;

	r = log(n + 1) / log(ITER_MAX + 1) * 255;
	g = n * 255 / ITER_MAX;
	b = 0;
	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(r, g, b));
}

void	zer(double n, int *r, int *g, int *b)
{
	double	t;

	t = n / ITER_MAX;
	*r = (int)(9 * (1 - t) * t * t * t * 255);
	*g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	*b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void	test(t_data *data, t_pixel pixel, double n)
{	
	int r, g, b, color;

	if (n > ITER_MAX)
		color = encode_rgb(0, 0, 0);
	else
	{
		zer(n, &r, &g, &b);
		color = encode_rgb(r, g, b);
	}

	pixel_put_in_image(&data->image, pixel.x, pixel.y, color);
}