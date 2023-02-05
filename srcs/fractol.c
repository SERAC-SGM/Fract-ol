/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:29:46 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/05 16:13:09 by lletourn         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	get_set(&data, argv[1]);
	get_color(&data, argv[2]);
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
