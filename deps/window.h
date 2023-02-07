/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:44:14 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/06 14:09:40 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

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

typedef struct s_data	t_data;

struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_image	image;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom_factor;
	double	move_factor;
	int		set;
	int		color;
	void	(*compute_set)(t_data *, t_pixel);
	void	(*display_set)(t_data *, t_pixel, double);
	double	julia_x;
	double	julia_y;
};

int		encode_rgb(__uint8_t red, __uint8_t green, __uint8_t blue);
void	pixel_put_in_image(t_image *image, int x, int y, int color);
void	free_and_exit(t_data *data);
int		handle_window_closed(t_data *data);
int		render(t_data *data);

#endif
