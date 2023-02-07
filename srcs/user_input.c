/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:30:50 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/07 15:38:45 by lletourn         ###   ########.fr       */
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

void	invalid_parameters_output(int n)
{
	if (n == 0)
	{
		ft_printf("\nInvalid number of parameters, exiting...\n\n\n");
		ft_printf("	Mandatory : 'set' and 'color'\n");
		ft_printf("	Optional : 'x' and 'y' (julia set only)\n\n");
		exit(0);
	}
	else if (n == 1)
	{
		ft_printf("\nInvalid set, exiting...\n\n\nSets:");
		ft_printf("	1.mandelbrot\n	2.fast_mandelbrot\n	3.julia\n");
		ft_printf("	4.burning_ship\n	5.fast_burning_ship\n\n");
		exit(0);
	}
}

void	get_set(t_data *data, int argc, char *arg)
{
	if (argc == 3 && !ft_strcmp("mandelbrot", arg))
			data->compute_set = &compute_mandelbrot_fractional_smooth;
	else if (argc == 3 && !ft_strcmp("fast_mandelbrot", arg))
			data->compute_set = &compute_mandelbrot;
	else if (argc == 3 && !ft_strcmp("burning_ship", arg))
			data->compute_set = &compute_burning_ship_fractional_smooth;
	else if (argc == 3 && !ft_strcmp("fast_burning_ship", arg))
			data->compute_set = &compute_burning_ship;
	else if (argc == 3 || argc == 5)
	{
		if (!ft_strcmp("julia", arg))
			data->compute_set = &compute_julia;
		else
			invalid_parameters_output(1);
	}
	else
		invalid_parameters_output(0);
}

void	get_color(t_data *data, char *arg)
{
	if (!ft_strcmp("monochromatic", arg))
		data->display_set = &monochrome_gradient;
	else if (!ft_strcmp("colorful", arg))
		data->display_set = &display_color;
	else
	{
		ft_printf("\n\nInvalid color, exiting...\n\n\nColors:");
		ft_printf("	1.monochromatic\n	2.colorful\n\n");
		exit(0);
	}	
}

void	get_julia_params(t_data *data, int argc, char **argv)
{
	double	x;
	double	y;

	if (ft_strcmp("julia", argv[1]))
		return ;
	if (argc == 3)
	{
		data->julia_x = -0.9;
		data->julia_y = 0.27015;
		ft_printf("Rendering Julia set with default z0 = (-0.9 + 0.27015j)\n");
		return ;
	}
	x = ft_atof(argv[3]);
	y = ft_atof(argv[4]);
	data->julia_x = x;
	data->julia_y = y;
}
