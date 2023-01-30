/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:59:47 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/28 17:20:59 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include <X11/keysym.h>

# define SCROLL_UP 4
# define SCROLL_DOWN 5

int	handle_keypress(int keysym, t_data *data);
int	handle_mouse_input(int button, int x, int y, t_data *data);

#endif
