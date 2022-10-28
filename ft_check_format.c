/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:26 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/28 02:19:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, int old_i, int new_i, t_print *tab)
{
	if (format[new_i] == 'c')
		ft_format_c(tab);
	// else if (format[new_i] == 's')
	// 	ft_format_s(format, tab);
	// else if (format[new_i] == 'p')
	// 	ft_format_p(format, tab);
	// else if (format[new_i] == 'd')
	// 	ft_format_d(format, tab);
	// else if (format[new_i] == 'i')
	// 	ft_format_i(format, tab);
	// else if (format[new_i] == 'u')
	// 	ft_format_u(format, tab);
	// else if (format[new_i] == 'x')
	// 	ft_format_lx(format, tab);
	// else if (format[new_i] == 'X')
	// 	ft_format_ux(format, tab);
	// else if (format[new_i] == '%')
	// 	ft_format_per(format, tab);
	else
		return (old_i);
	return (new_i);
}
