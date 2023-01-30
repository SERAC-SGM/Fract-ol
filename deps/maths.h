/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:51:20 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/28 17:13:30 by lletourn         ###   ########.fr       */
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
int		render_mandelbrot(t_data *data);

#endif
