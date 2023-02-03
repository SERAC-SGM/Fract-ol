/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:55:52 by lletourn          #+#    #+#             */
/*   Updated: 2023/01/23 15:46:52 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define CONV_SPECIFIERS "cspdiuxX%"

typedef struct s_format_specifier
{
	char	minus_flag;
	char	zero_flag;
	int		width;
	int		precision_dot;
	int		precision;
	int		negative_number;
	char	type;
}			t_format_specifier;

t_format_specifier	ft_init_format_specifier(void);
t_format_specifier	ft_check_type(char *str, t_format_specifier fs);

int					ft_strlen(char *str);

void				ft_writechar(char c, int *len);
void				ft_writestr(char *str, int *len);

void				ft_writenbr(int n, int *len);
void				ft_writeunsigned(unsigned int n, int *len);
void				ft_writenbr_hex(unsigned int n, int *len, char c);
void				ft_writeptr(unsigned long long ptr, int *len);

void				ft_convert_type(char type, int *len, va_list ap);

int					ft_printf(const char *format, ...);

#endif
