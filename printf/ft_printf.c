/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:43:42 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/23 15:47:24 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(t_format_specifier fs, int *len, va_list ap, size_t *i)
{
	ft_convert_type(fs.type, len, ap);
	(*i)++;
}

int	ft_printf(const char *format, ...)
{
	va_list				ap;
	size_t				i;
	int					len;
	t_format_specifier	fs;

	va_start(ap, format);
	i = 0;
	len = 0;
	fs = ft_init_format_specifier();
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_writechar(format[i], &len);
		else
		{
			fs = ft_check_type((char *)(format + i + 1), fs);
			if (fs.type)
				ft_aux(fs, &len, ap, &i);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
