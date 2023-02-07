/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:26:08 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/07 15:35:08 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	compute_mandelbrot(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;

	set_zero(&z);
	set_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	if (iter == ITER_MAX)
		data->display_set(data, pixel, iter);
	else
		data->display_set(data, pixel, iter);
}

void	compute_mandelbrot_fractional_smooth(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;
	double		smoothed;

	set_zero(&z);
	set_cartesian(data, &pixel, &z0);
	iter = 0;
	smoothed = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
		get_smooth(&smoothed, iter, z);
	}
	if (iter == ITER_MAX)
		data->display_set(data, pixel, 0);
	else
		data->display_set(data, pixel, smoothed);
}

void	compute_julia(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;

	set_cartesian(data, &pixel, &z);
	set_complex(&z0, data->julia_x, data->julia_y);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = z.x * z.x - z.y * z.y + z0.x;
		z.y = 2 * z.x * z.y + z0.y;
		z.x = temp;
		iter++;
	}
	if (iter == ITER_MAX)
		data->display_set(data, pixel, 0);
	else
		data->display_set(data, pixel, iter);
}

void	compute_burning_ship(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;

	set_zero(&z);
	set_cartesian(data, &pixel, &z0);
	iter = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = fabs(z.x * z.x - z.y * z.y + z0.x);
		z.y = fabs(2 * z.x * z.y + z0.y);
		z.x = temp;
		iter++;
	}
	if (iter == ITER_MAX)
		data->display_set(data, pixel, iter);
	else
		data->display_set(data, pixel, iter);
}

void	compute_burning_ship_fractional_smooth(t_data *data, t_pixel pixel)
{
	t_complex	z;
	t_complex	z0;
	double		temp;
	int			iter;
	double		smoothed;

	set_zero(&z);
	set_cartesian(data, &pixel, &z0);
	iter = 0;
	smoothed = 0;
	while (z.x * z.x + z.y * z.y <= 4 && iter < ITER_MAX)
	{
		temp = fabs(z.x * z.x - z.y * z.y + z0.x);
		z.y = fabs(2 * z.x * z.y + z0.y);
		z.x = temp;
		iter++;
		get_smooth(&smoothed, iter, z);
	}
	if (iter == ITER_MAX)
		data->display_set(data, pixel, 0);
	else
		data->display_set(data, pixel, smoothed);
}
