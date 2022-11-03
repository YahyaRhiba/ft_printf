/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:54:06 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/03 17:36:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xcheck_hash(char *nbr, t_print *tab, const char *prefix)
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
		rtn = ft_zerospaces_s(rtn, '0', tab->p_num - 2);
		rtn = ft_xcheck_hash(rtn, tab, prefix);
		return (free(nbr), rtn);
	}
	rtn = ft_zerospaces_s(nbr, '0', tab->p_num);
	return (free(nbr), rtn);
}

char	*ft_format_x_usingflags(char *nbr, t_print *tab, const char *prefix)
{
	nbr = ft_xcheck_hash(nbr, tab, prefix);
	nbr = ft_xcheck_point(nbr, tab, prefix);
	return (NULL);
}
