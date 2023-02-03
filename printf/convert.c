/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:19:40 by lletourn          #+#    #+#             */
/*   Updated: 2022/12/29 11:47:06 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_type(char type, int *len, va_list ap)
{
	if (type == 'c')
		ft_writechar(va_arg(ap, int), len);
	else if (type == 's')
		ft_writestr(va_arg(ap, char *), len);
	else if (type == 'p')
		ft_writeptr(va_arg(ap, unsigned long long), len);
	else if (type == 'd' || type == 'i')
		ft_writenbr(va_arg(ap, int), len);
	else if (type == 'u')
		ft_writeunsigned(va_arg(ap, int), len);
	else if (type == 'x')
		ft_writenbr_hex(va_arg(ap, unsigned int), len, 'x');
	else if (type == 'X')
		ft_writenbr_hex(va_arg(ap, unsigned int), len, 'X');
	else if (type == '%')
		ft_writechar('%', len);
}
