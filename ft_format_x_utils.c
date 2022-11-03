/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:54:06 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/03 23:01:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xcheck_hash(char *nbr, t_print *tab, const char *prefix, int f)
{
	char	*rtn;

	if (!tab->hash)
		return (nbr);
	if (*nbr == '0' && ft_strlen(nbr) == 1 && f)
		return (nbr);
	rtn = ft_strjoin(prefix, nbr);
	return (free(nbr), rtn);
}

char	*ft_xcheck_point(char *nbr, t_print *tab, const char *prefix)
{
	char	*rtn;
	size_t	nlen;

	if (!tab->point || !nbr)
		return (nbr);
	if (nbr[1] == 'x' || nbr[1] == 'X')
	{
		nlen = ft_strlen(nbr + 2);
		rtn = (char *)calloc((nlen + 1), sizeof(char));
		if (!rtn)
			return (free(nbr), NULL);
		ft_strlcpy(rtn, (nbr + 2), nlen + 1);
		rtn = ft_zerospaces_s(rtn, '0', tab->p_num);
		rtn = ft_xcheck_hash(rtn, tab, prefix, 0);
		return (free(nbr), rtn);
	}
	rtn = ft_zerospaces_s(nbr, '0', tab->p_num);
	return (rtn);
}

char	*ft_format_x_usingflags(char *nbr, t_print *tab, const char *prefix, int f)
{
	nbr = ft_xcheck_hash(nbr, tab, prefix, f);
	nbr = ft_xcheck_point(nbr, tab, prefix);
	if (nbr && tab->mines)
		nbr = ft_mins_s(nbr, tab);
	else if (nbr && tab->zero && !tab->point)
	{
		tab->point = 1;
		tab->p_num = tab->w_nbr;
		nbr = ft_xcheck_point(nbr, tab, prefix);
	}
	else if (nbr && tab->width)
		nbr = ft_zerospaces_s(nbr, 32, tab->w_nbr);
	return (nbr);
}
