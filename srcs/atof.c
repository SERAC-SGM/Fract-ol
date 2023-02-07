/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:15 by lletourn          #+#    #+#             */
/*   Updated: 2023/02/07 15:19:25 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/fractol.h"

static double	get_sign(char c, int *index)
{
	if (c == '-')
	{
		(*index)++;
		return (-1.0);
	}
	else if (c == '+' || (c > 47 && c < 58))
	{
		(*index)++;
		return (1.0);
	}
	else
		return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		decimal_part;
	int		sign;
	float	result;

	i = 0;
	decimal_part = 0;
	result = 0;
	while (str[i])
	{
		sign = get_sign(str[i], &i);
		while (str[i] > 47 && str[i] < 58 && str[i] != 46)
			result = result * 10 + str[i++] - '0';
		if (str[i++] != 46)
			return (0);
		while (str[i] > 47 && str[i] <= 58)
		{
			result = result * 10 + str[i++] - '0';
			decimal_part++;
		}
		while (decimal_part-- > 0)
			result *= 0.1;
	}
	return (sign * result);
}
