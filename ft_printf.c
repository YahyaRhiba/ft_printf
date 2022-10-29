/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:46:22 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/29 14:55:54 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char c, int i, t_print *tab)
{
	while (i-- > 0)
		tab->len += write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		rtn;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab || !format)
		return (free(tab), -1);
	va_start(tab->args, format);
	rtn = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_init_tab(tab);
			i = ft_check_format(format, i, ft_check_flags(format, i + 1,
						tab), tab);
			rtn += tab->len;
		}
		else
			rtn += write(1, format + i, 1);
	}
	return (va_end(tab->args), free(tab), rtn);
}
