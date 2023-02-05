/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:51:20 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/05 16:33:20 by lletourn         ###   ########.fr       */
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

void	set_zero(t_complex *z);
void	set_complex(t_complex *z, double n1, double n2);
void	set_cartesian(t_data *data, t_pixel *pixel, t_complex *z);
int		render_each_pixel(t_data *data);

#endif
