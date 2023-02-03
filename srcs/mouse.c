/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:42 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/03 16:38:10 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	zoom_in(t_data *data, t_complex coordinates)
{
	data->xmin = coordinates.x
		+ (data->xmin - coordinates.x) / data->zoom_factor;
	data->xmax = coordinates.x
		+ (data->xmax - coordinates.x) / data->zoom_factor;
	data->ymin = coordinates.y
		+ (data->ymin - coordinates.y) / data->zoom_factor;
	data->ymax = coordinates.y
		+ (data->ymax - coordinates.y) / data->zoom_factor;
}

void	zoom_out(t_data *data, t_complex coordinates)
{
	data->xmin = coordinates.x
		+ (data->xmin - coordinates.x) * data->zoom_factor;
	data->xmax = coordinates.x
		+ (data->xmax - coordinates.x) * data->zoom_factor;
	data->ymin = coordinates.y
		+ (data->ymin - coordinates.y) * data->zoom_factor;
	data->ymax = coordinates.y
		+ (data->ymax - coordinates.y) * data->zoom_factor;
}

int	handle_mouse_input(int button, int x, int y, t_data *data)
{
	t_complex	mouse_cartesian;
	t_pixel		mouse_position;

	mouse_position.x = x;
	mouse_position.y = y;
	convert_to_cartesian(data, &mouse_position, &mouse_cartesian);
	if (button == SCROLL_UP)
		zoom_in(data, mouse_cartesian);
	else if (button == SCROLL_DOWN)
		zoom_out(data, mouse_cartesian);
	render(data);
	return (0);
}
