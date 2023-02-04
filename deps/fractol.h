/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:26:24 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 15:15:21 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MLX_ERROR 1

# include <stdlib.h>
# include <unistd.h>

# include "window.h"
# include "colors.h"
# include "maths.h"
# include "mouse_and_keys.h"
# include "user_input.h"

# define ITER_MAX 1000

# define XMAX 1.5
# define XMIN -3
# define YMAX 1.5
# define YMIN -1.5

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800

# define ZOOM_FACTOR 1.1
# define MOVE_FACTOR 0.05

#endif
