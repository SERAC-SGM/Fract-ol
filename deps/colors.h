/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:03:10 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/04 15:03:48 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

void	linear_gradient(t_data *data, t_pixel pixel, double n);
void	monochrome_gradient(t_data *data, t_pixel pixel, double n);
void	monochrome_gradient_reverse(t_data *data, t_pixel pixel, double n);
void	psychedelic_bnw(t_data *data, t_pixel pixel, double n);
void	color_map(t_data *data, t_pixel pixel, double n);
void	psychedelic1(t_data *data, t_pixel pixel, double n);
void	psychedelic2(t_data *data, t_pixel pixel, double n);
void	logarithmic_color_shift(t_data *data, t_pixel pixel, double n);

#endif