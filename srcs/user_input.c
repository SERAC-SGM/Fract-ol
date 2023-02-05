/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:30:50 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 17:52:07 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"
#include "../printf/ft_printf.h"

void	get_set(t_data *data)
{
	char	set;
	char	tmp;

	ft_printf("\n	Set	1: Mandelbrot set\n		2: Julia set\n");
	ft_printf("		3: Mandelbrot set without fractional escape count");
	ft_printf(" (faster)\n\n");
	ft_printf("Enter selection: ");
	read(0, &set, 1);
	read(0, &tmp, 1);
	if (set == '1')
		data->compute_set = &compute_mandelbrot_fractional;
	else if (set == '2')
	{
		ft_printf("\n\nwork in progress... exiting\n\n");
		exit(0);
	}
	else if (set == '3')
		data->compute_set = &compute_mandelbrot;
	else if (set == '4')
	{
		ft_printf("\n\nwork in progress... exiting\n\n");
		exit(0);
	}
	else
	{
		ft_printf("\n\nselection outside range... exiting\n\n");
		exit(0);
	}
}

void	get_color(t_data *data)
{
	char	color;

	ft_printf("\n\n\n\n	Color	1: black and white\n		2: colorful\n");
	ft_printf("		3: psychedelic\n\n");
	ft_printf("Enter selection: ");
	read(0, &color, 1);
	if (color == '1')
		data->display_set = &monochrome_gradient;
	else if (color == '2')
		data->display_set = &test;
	else if (color == '3')
		data->display_set = &psychedelic1;
	else
	{
		ft_printf("\n\nselection outside range... exiting\n\n");
		exit(0);
	}
}
