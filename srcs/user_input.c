/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:30:50 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/07 15:17:07 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"
#include "../printf/ft_printf.h"



#include <stdio.h>

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
		ft_printf("	1.mandelbrot\n	2.fast_mandelbrot\n	3.julia\n\n");
		exit(0);
	}
}

void	get_set(t_data *data, int argc, char *arg)
{
	if (argc == 3 && !ft_strcmp("mandelbrot", arg))
			data->compute_set = &compute_mandelbrot_fractional_smooth;
	else if (argc == 3 && !ft_strcmp("fast_mandelbrot", arg))
			data->compute_set = &compute_mandelbrot;
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

	if (argc == 3)
	{
		data->julia_x = -0.9;
		data->julia_y = 0.27015;
		printf("Rendering Julia set with default z0 = (%lf +j %lf)\n", data->julia_x, data->julia_y);
		return ;
	}
	ft_printf("argv : %s %s\n", argv[3], argv [4]);
	x = ft_atof(argv[3]);
	y = ft_atof(argv[4]);
	printf("x = %lf, y = %lf\n", x, y);
	data->julia_x = x;
	data->julia_y = y;
	printf("Rendering Julia set with complex z0 = (%lf +i %lf)\n", data->julia_x, data->julia_y);
}
