/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:46:22 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 03:20:21 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		rtn;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab || !format)
		return (free(tab), -1);
	tab->buff = (char *)ft_calloc(1, sizeof(char));
	if (!tab->buff)
		return (free(tab), -1);
	tab->buflen = 0;
	va_start(tab->args, format);
	rtn = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			rtn += ft_format(format, &i, tab);
		else
			rtn += ft_addchar(tab, (char)*(format + i));
		if (tab->error == 1)
			return (free(tab->buff), free(tab), -1);
	}
	write(1, tab->buff, tab->buflen);
	return (va_end(tab->args), free(tab->buff), free(tab), rtn);
}
