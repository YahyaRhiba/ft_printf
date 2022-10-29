/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:26 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/29 14:52:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, int old_i, int new_i, t_print *tab)
{
	if (format[new_i] == 'c')
		ft_format_c(tab);
	else if (format[new_i] == 's')
		ft_format_s(tab);
	// else if (format[new_i] == 'p')
	// 	ft_format_p(tab);
	// else if (format[new_i] == 'd')
	// 	ft_format_d(tab);
	// else if (format[new_i] == 'i')
	// 	ft_format_i(tab);
	// else if (format[new_i] == 'u')
	// 	ft_format_u(tab);
	// else if (format[new_i] == 'x')
	// 	ft_format_lx(tab);
	// else if (format[new_i] == 'X')
	// 	ft_format_ux(tab);
	// else if (format[new_i] == '%')
	// 	ft_format_per(tab);
	else
		return (old_i);
	return (new_i);
}
