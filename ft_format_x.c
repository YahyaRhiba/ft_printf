/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:00:52 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 22:07:41 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	# :
	+ :
space :
	- :
	. :
	0 :
widht :

*/


char	*ft_format_x_usingflags(char *nbr, t_print *tab, char *prefix)
{
	if (tab->point)
		ft_precision_s(nbr, tab);
	else if (tab->mines == 0 && tab->zero == 1)
		ft_
}


int	ft_format_x(t_print *tab, const char *base, const char *prefix)
{
	char	*nbr;

	nbr = ft_converthex(va_arg(tab->args, unsigned int), base);
	if (!nbr)
		return (tab->error = 1, -1);
	nbr = ft_format_x_usingflags(nbr, tab, prefix);
	if (!nbr)
		return (tab->error = 1, -1);
	ft_addstr(nbr, tab);
	return (1);
}
