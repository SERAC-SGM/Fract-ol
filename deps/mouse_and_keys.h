/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:59:47 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/05 15:40:28 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_AND_KEYS_H
# define MOUSE_AND_KEYS_H

# include <X11/keysym.h>

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define WINDOW_CLOSED 17

int	handle_keypress(int keysym, t_data *data);
int	handle_mouse_input(int button, int x, int y, t_data *data);

#endif
