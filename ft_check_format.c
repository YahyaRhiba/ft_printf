/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:20:26 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/30 18:26:51 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, int i, t_print *tab)
{
	if (format[i] == 'c')
		ft_format_c(tab, va_arg(tab->args, int));
	else if (format[i] == 's')
		ft_format_s(tab);
	else if (format[i] == '%')
		ft_format_c(tab, '%');
	else
		ft_format_c(tab, format[i]);
	return (i);
}

/*
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
*/
