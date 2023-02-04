/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:51:20 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 14:55:41 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

void	convert_to_cartesian(t_data *data, t_pixel *pixel, t_complex *z);
void	compute_mandelbrot_fractional(t_data *data, t_pixel pixel);
void	compute_mandelbrot(t_data *data, t_pixel pixel);
int		render_each_pixel(t_data *data);

#endif
