/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:27:18 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/06 15:11:53 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_H
# define USER_INPUT_H

void	get_set(t_data *data, int argc, char *arg);
void	get_color(t_data *data, char *arg);
void	invalid_parameters_output(int n);
void	get_julia_params(t_data *data, int argc, char **argv);

#endif
