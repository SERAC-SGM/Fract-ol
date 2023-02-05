/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:30:50 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/05 16:38:46 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"
#include "../printf/ft_printf.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	get_set(t_data *data, char *arg)
{
	if (!arg)
	{
		ft_printf("\nEmpty parameter, exiting...\n\n\nParameters:");
		ft_printf("	1.mandelbrot\n		2.fast_mandelbrot\n		3.julia\n\n");
		exit(0);
	}
	if (!ft_strcmp("mandelbrot", arg))
		data->compute_set = &compute_mandelbrot_fractional_smooth;
	else if (!ft_strcmp("fast_mandelbrot", arg))
		data->compute_set = &compute_mandelbrot;
	else if (!ft_strcmp("julia", arg))
		data->compute_set = &compute_julia;
	else
	{
		ft_printf("\nInvalid parameter, exiting...\n\n\nParameters:");
		ft_printf("	1.mandelbrot\n		2.fast_mandelbrot\n		3.julia\n\n");
		exit(0);
	}
}

void	get_color(t_data *data, char *arg)
{
	if (!arg)
	{
		ft_printf("\n\nEmpty parameter, exiting...\n\nParameters:");
		ft_printf("	1.monochromatic\n		2.colorful\n\n");
		exit(0);
	}	
	if (!ft_strcmp("monochromatic", arg))
		data->display_set = &monochrome_gradient;
	else if (!ft_strcmp("colorful", arg))
		data->display_set = &display_color;
	else
	{
		ft_printf("\n\nInvalid parameter, exiting...\n\nParameters:");
		ft_printf("	1.monochromatic\n		2.colorful\n\n");
		exit(0);
	}	
}



// void	get_set(t_data *data)
// {
// 	char	set;
// 	char	tmp;

// 	ft_printf("\n	Set	1: Mandelbrot set\n		2: Julia set\n");
// 	ft_printf("		3: Mandelbrot set without fractional escape count");
// 	ft_printf(" (faster)\n\n");
// 	ft_printf("Enter selection: ");
// 	read(0, &set, 1);
// 	read(0, &tmp, 1);
// 	if (set == '1')
// 		data->compute_set = &compute_mandelbrot_fractional_smooth;
// 	else if (set == '2')
// 	{
// 		ft_printf("\n\nwork in progress... exiting\n\n");
// 		exit(0);
// 	}
// 	else if (set == '3')
// 		data->compute_set = &compute_mandelbrot;
// 	else if (set == '4')
// 	{
// 		ft_printf("\n\nwork in progress... exiting\n\n");
// 		exit(0);
// 	}
// 	else
// 	{
// 		ft_printf("\n\nselection outside range... exiting\n\n");
// 		exit(0);
// 	}
// }

// void	get_color(t_data *data)
// {
// 	char	color;

// 	ft_printf("\n\n\n\n	Color	1: black and white\n		2: colorful\n");
// 	ft_printf("		3: psychedelic\n\n");
// 	ft_printf("Enter selection: ");
// 	read(0, &color, 1);
// 	if (color == '1')
// 		data->display_set = &monochrome_gradient;
// 	else if (color == '2')
// 		data->display_set = &display_color;
// 	else
// 	{
// 		ft_printf("\n\nselection outside range... exiting\n\n");
// 		exit(0);
// 	}
// }
