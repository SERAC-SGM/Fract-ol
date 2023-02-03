/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:52:09 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/29 10:19:51 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_specifier	ft_init_format_specifier(void)
{
	t_format_specifier	fs;

	fs.minus_flag = 0;
	fs.zero_flag = 0;
	fs.width = 0;
	fs.precision = 0;
	fs.type = 0;
	return (fs);
}

t_format_specifier	ft_check_type(char *str, t_format_specifier fs)
{
	int		i;
	char	*conv_spec;

	i = 0;
	conv_spec = CONV_SPECIFIERS;
	while (conv_spec[i] != '\0')
	{
		if (str[0] == conv_spec[i])
		{
			fs.type = conv_spec[i];
			return (fs);
		}
		i++;
	}
	fs.type = 0;
	return (fs);
}
