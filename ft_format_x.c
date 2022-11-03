/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:00:52 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/03 23:44:12 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_x(t_print *tab, const char *base, const char *prefix)
{
	char			*nbr;
	unsigned int	n;

	n = va_arg(tab->args, unsigned int);
	nbr = ft_converthex(n, base);
	if (!nbr)
		return (tab->error = 1, -1);
	nbr = ft_format_x_usingflags(nbr, tab, prefix, 1);
	if (!nbr)
		return (tab->error = 1, -1);
	ft_addstr(nbr, tab);
	return (free(nbr), 1);
}
