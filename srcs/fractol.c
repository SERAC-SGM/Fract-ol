/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:29:46 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/03 17:19:17 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

static int	init_data(t_data *data)
{
	data->xmax = XMAX;
	data->xmin = XMIN;
	data->ymax = YMAX;
	data->ymin = YMIN;
	data->zoom_factor = ZOOM_FACTOR;
	data->move_factor = MOVE_FACTOR;
	data->x_offset = 0.0;
	data->y_offset = 0.0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free (data->mlx_ptr), MLX_ERROR);
	data->window_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
	data->image.mlx_image = mlx_new_image(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image.address = mlx_get_data_addr(data->image.mlx_image,
			&data->image.bits_per_pixel,
			&data->image.line_length, &data->image.endian);
	if (!data->window_ptr)
		return (free(data->window_ptr), MLX_ERROR);
	return (0);
}

int	render(t_data *data)
{
	if (!data->window_ptr)
		return (1);
	render_mandelbrot(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->image.mlx_image, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	if (init_data(&data))
		return (MLX_ERROR);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_mouse_hook(data.window_ptr, &handle_mouse_input, &data);
	mlx_hook(data.window_ptr, KeyPress,
		KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.window_ptr, WINDOW_CLOSED,
		LeaveWindowMask, &handle_window_closed, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
