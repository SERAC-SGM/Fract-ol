/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:26:24 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/03 17:29:21 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MLX_ERROR 1

# include <stdlib.h>
# include <unistd.h>

# include "window.h"
# include "input.h"
# include "maths.h"

# define ITER_MAX 1000

# define XMAX 1.5
# define XMIN -3
# define YMAX 1.5
# define YMIN -1.5

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800

# define ZOOM_FACTOR 1.1
# define MOVE_FACTOR 0.05

int		render(t_data *data);

// COLORS FUNCTIONS
//  standard iteration count
void	linear_gradient(t_data *data, t_pixel pixel, int n);
void	monochrome_gradient(t_data *data, t_pixel pixel, int n);
void	monochrome_gradient_reverse(t_data *data, t_pixel pixel, int n);
void	psychedelic0(t_data *data, t_pixel pixel, int n);
void	color_map(t_data *data, t_pixel pixel, int n);
// fractional iteration count
void	monochrome_gradient_fract(t_data *data, t_pixel pixel, double n);
void	psychedelic1(t_data *data, t_pixel pixel, double n);
void	psychedelic2(t_data *data, t_pixel pixel, double n);
void	logarithmic_color_shift(t_data *data, t_pixel pixel, double n);

#endif
