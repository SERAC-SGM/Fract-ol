/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:26:34 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/05 16:28:29 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_H
# define SETS_H

void	compute_mandelbrot(t_data *data, t_pixel pixel);
void	compute_mandelbrot_fractional_smooth(t_data *data, t_pixel pixel);
void	compute_julia(t_data *data, t_pixel pixel);

#endif
