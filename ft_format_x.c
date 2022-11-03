/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:00:52 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/03 15:59:35 by yrhiba           ###   ########.fr       */
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

char	*ft_xcheck_hash(char *nbr, t_print *tab, char *prefix)
{
	char	*rtn;

	if (!tab->hash)
		return (nbr);
	rtn = (char *)ft_calloc(1, sizeof(char));
	if (!rtn)
		return (free(nbr), NULL);
	rtn = ft_strjoin(prefix, nbr);
	return (free(nbr), rtn);
}

char	*ft_xcheck_point(char *nbr, t_print *tab, char *prefix)
{
	char	*rtn;

	if (!tab->point || !nbr)
		return (nbr);
	rtn = (char *)ft_calloc((tab->p_num + 1), sizeof(char));
	if (!rtn)
		return (free(nbr), NULL);
	rtn = ft_strjoin(prefix, nbr);
	return (free(nbr), rtn);
}

char	*ft_format_x_usingflags(char *nbr, t_print *tab, char *prefix)
{
	nbr = ft_xcheck_hash(nbr, tab, prefix);
	nbr = ft_xcheck_point(nbr, tab);
	nbr = ft_xcheck_mins(nbr, tab);
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
