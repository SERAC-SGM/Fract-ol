/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:03:10 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/07 17:12:43 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

void	monochrome_gradient(t_data *data, t_pixel pixel, double n);
void	color1(double n, int *r, int *g, int *b);
void	color2(double n, int *r, int *g, int *b);
void	change_color(t_data *data);
void	display_color(t_data *data, t_pixel pixel, double n);

#endif
