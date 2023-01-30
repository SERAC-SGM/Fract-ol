/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:44:14 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:27 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

# define WINDOW_CLOSED 17

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;

typedef struct s_image
{
	void	*mlx_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_image	image;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom_factor;
	double	x_offset;
	double	y_offset;
}			t_data;

int		encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue);
void	pixel_put_in_image(t_image *image, int x, int y, int color);
void	free_and_exit(t_data *data);
int		handle_window_closed(t_data *data);

#endif
