/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:25:52 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/12 12:21:10 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writenbr(int n, int *len)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		ft_writechar('-', len);
	}
	if (nbr >= 10)
	{
		ft_writenbr(nbr / 10, len);
		ft_writenbr(nbr % 10, len);
	}
	else
		ft_writechar(nbr + '0', len);
}

void	ft_writeunsigned(unsigned int n, int *len)
{
	long unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_writeunsigned(nbr / 10, len);
		ft_writeunsigned(nbr % 10, len);
	}
	else
		ft_writechar(nbr + '0', len);
}

void	ft_writenbr_hex(unsigned int n, int *len, char c)
{
	char		*hexb;
	long int	nbr;

	nbr = n;
	if (c == 'x')
		hexb = "0123456789abcdef";
	else if (c == 'X')
		hexb = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_writenbr_hex(nbr / 16, len, c);
		ft_writenbr_hex(nbr % 16, len, c);
	}
	else
		ft_writechar(hexb[nbr], len);
}

static void	ft_ptr(unsigned long long ptr, int *len)
{
	char	*hexb;

	hexb = "0123456789abcdef";
	if (ptr > 15)
	{
		ft_ptr(ptr / 16, len);
		ft_ptr(ptr % 16, len);
	}
	else
		ft_writechar(hexb[ptr], len);
}

void	ft_writeptr(unsigned long long ptr, int *len)
{
	if (ptr == 0)
	{
		ft_writestr("(nil)", len);
		return ;
	}
	ft_writestr("0x", len);
	ft_ptr(ptr, len);
}
