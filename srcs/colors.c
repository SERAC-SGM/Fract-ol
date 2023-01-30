/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:32:52 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/29 11:43:19 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	linear_gradient(t_data *data, t_pixel pixel, int n)
{
	int	r;
	int	g;
	int	b;

	r = n * 255 / ITER_MAX;
	g = 0;
	b = 255 - r;
	pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(r, g, b));
}

void	monochrome_gradient(t_data *data, t_pixel pixel, int n)
{
	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(n * 255 / ITER_MAX, n * 255 / ITER_MAX, n * 255 / ITER_MAX));
}

void	monochrome_gradient_reverse(t_data *data, t_pixel pixel, int n)
{
	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(255 - (n * 255 / ITER_MAX), 255
			- (n * 255 / ITER_MAX), 255 - (n * 255 / ITER_MAX)));
}

void	psychedelic0(t_data *data, t_pixel pixel, int n)
{
	if (n % 2 != 0)
		pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(255, 255, 255));
	else
		pixel_put_in_image(&data->image, pixel.x, pixel.y, encode_rgb(0, 0, 0));

}

void	color_map(t_data *data, t_pixel pixel, int n)
{
	unsigned char	color[3];

	if (n < ITER_MAX / 3)
	{
		color[0] = 127;
		color[1] = n * 3 * 200 / ITER_MAX;
		color[2] = 255;
	}
	else if (n < 2 * ITER_MAX / 3)
	{
		color[0] = (ITER_MAX - n) * 3 * 50 / ITER_MAX;
		color[1] = 100;
		color[2] = 200;
	}
	else
	{
		color[0] = 50;
		color[1] = 140;
		color[2] = (n - 2 * ITER_MAX / 3) * 3 * 123 / ITER_MAX;
	}
	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(color[0], color[1], color[2]));
}

void	monochrome_gradient_fract(t_data *data, t_pixel pixel, double n)
{
	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(n * 255 / ITER_MAX, n * 255 / ITER_MAX, n * 255 / ITER_MAX));
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

void	psychedelic2(t_data *data, t_pixel pixel, double n)
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

static double	lerp(double a, double b, double t)
{
	return (a + t * (b - a));
}

void	logarithmic_color_shift(t_data *data, t_pixel pixel, double n)
{
	double	ratio = n / ITER_MAX;
	int	r = (int)lerp(0, 255, ratio);
	int	g = (int)lerp(0, 100, ratio);
	int	b = (int)lerp(100, 255, ratio);
	//int	g = (int)(255 * ratio);
	//int	b = (int)(255 * (1 - ratio));

	pixel_put_in_image(&data->image, pixel.x, pixel.y,
		encode_rgb(r, g, b));
}
