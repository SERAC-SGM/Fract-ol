/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:46:44 by lletourn          #+#    #+#             */
/*   Updated: 2022/12/28 17:44:52 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_writechar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_writestr(char *str, int *len)
{
	int	length;

	if (!str)
	{
		ft_writestr("(null)", len);
		return ;
	}
	length = ft_strlen(str);
	*len += length;
	write(1, str, length);
}
