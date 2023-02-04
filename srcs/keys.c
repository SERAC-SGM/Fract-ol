/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:57:17 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 14:32:08 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

void	move_view(t_data *data, char direction)
{
	if (direction == 'u')
	{
		data->ymin = data->ymin - (data->ymax - data->ymin) * data->move_factor;
		data->ymax = data->ymax - (data->ymax - data->ymin) * data->move_factor;
	}
	else if (direction == 'd')
	{
		data->ymin = data->ymin + (data->ymax - data->ymin) * data->move_factor;
		data->ymax = data->ymax + (data->ymax - data->ymin) * data->move_factor;
	}
	else if (direction == 'l')
	{
		data->xmin = data->xmin - (data->xmax - data->xmin) * data->move_factor;
		data->xmax = data->xmax - (data->xmax - data->xmin) * data->move_factor;
	}
	else if (direction == 'r')
	{
		data->xmin = data->xmin + (data->xmax - data->xmin) * data->move_factor;
		data->xmax = data->xmax + (data->xmax - data->xmin) * data->move_factor;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_and_exit(data);
	else if (keysym == XK_Up)
		move_view(data, 'u');
	else if (keysym == XK_Down)
		move_view(data, 'd');
	else if (keysym == XK_Left)
		move_view(data, 'l');
	else if (keysym == XK_Right)
		move_view(data, 'r');
	return (0);
}
