/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:38:18 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/01 17:02:20 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_d_pluspace(char *nbr, int c)
{
	char	*rtn;
	size_t	size;
	size_t	i;

	if (nbr[0] == '-')
		return (nbr);
	size = ft_strlen(nbr) + 2;
	rtn = (char *)malloc(sizeof(char) * size);
	if (!rtn)
		return (free(nbr), NULL);
	i = 0;
	rtn[i] = c;
	while (++i < size - 1)
		rtn[i] = nbr[i - 1];
	return (rtn[i] = '\0', free(nbr), rtn);
}

char	*ft_format_d_precision(char *nbr, t_print *tab)
{
	char	*rtn;
	char	*tmp;
	size_t	numlen;
	size_t	i;
	size_t	j;

	numlen = ft_strlen(nbr);
	if (tab->p_num <= (int)numlen)
		return (nbr);
	rtn = (char *)malloc(sizeof(char *) * (tab->p_num + 1));
	if (!rtn)
		return (free(nbr), NULL);
	tmp = rtn;
	j = 0;
	if (nbr[j] == '-')
	{
		numlen -= 1;
		*tmp++ = nbr[j++];
	}
	i = -1;
	while (++i < (size_t)(tab->p_num - (int)numlen))
		*tmp++ = '0';
	while (nbr[j])
		*tmp++ = nbr[j++];
	return (*tmp = '\0', free(nbr), rtn);
}

char	*ft_format_d_usingflags(char *nbr, t_print *tab)
{
	if (tab->point == 1)
		nbr = ft_format_d_precision(nbr, tab);
	if (tab->plus == 1)
		nbr = ft_format_d_pluspace(nbr, '+');
	else if (tab->space == 1)
		nbr = ft_format_d_pluspace(nbr, 32);
	return (nbr);
}

int	ft_format_d(t_print *tab)
{
	char	*nbr;

	nbr = ft_itoa(va_arg(tab->args, int));
	if (!nbr)
		return (0);
	nbr = ft_format_d_usingflags(nbr, tab);
	if (!nbr)
		return (0);
	ft_print_str((const char *)nbr, tab);
	return (free(nbr), 0);
}

/*

	HASH	: NO
	SPACE 	: YES IGNORED IF + EXIST
	PLUS	: YES
	MINS	: YES
	WIDTH	: YES
	ZEROS	: YES IGNORED IF PRES OR MINS EXIST
	PRECS	: YES

*/
