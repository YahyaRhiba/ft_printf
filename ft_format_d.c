/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:38:18 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/03 16:00:51 by yrhiba           ###   ########.fr       */
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

char	*ft_format_d_precision(char *nbr, size_t numlen, int len, int c)
{
	char	*rtn;
	char	*tmp;
	size_t	i;
	size_t	j;

	if (len < (int)numlen)
		return (nbr);
	rtn = (char *)malloc(sizeof(char *) * (len + 1));
	if (!rtn)
		return (free(nbr), NULL);
	tmp = rtn;
	j = 0;
	if ((nbr[j] == '-' || nbr[j] == '+') && c == '0')
	{
		if (nbr[j] == '-')
			numlen -= 1;
		*tmp++ = nbr[j++];
	}
	i = -1;
	while (++i < (size_t)(len - (int)numlen))
		*tmp++ = c;
	while (nbr[j])
		*tmp++ = nbr[j++];
	return (*tmp = '\0', free(nbr), rtn);
}

char	*ft_format_d_usingflags(char *nbr, t_print *tab)
{
	if (tab->point )
		nbr = ft_format_d_precision(nbr, ft_strlen(nbr), tab->p_num, '0');
	if (nbr && tab->plus)
		nbr = ft_format_d_pluspace(nbr, '+');
	else if (nbr && tab->space)
		nbr = ft_format_d_pluspace(nbr, 32);
	if (nbr && tab->mines)
		nbr = ft_mins_s(nbr, tab);
	else if (nbr && tab->zero && !tab->point)
		nbr = ft_format_d_precision(nbr, ft_strlen(nbr), tab->w_nbr, '0');
	else if (nbr && tab->width)
		nbr = ft_format_d_precision(nbr, ft_strlen(nbr), tab->w_nbr, 32);
	return (nbr);
}

int	ft_format_d(t_print *tab)
{
	char	*nbr;

	nbr = ft_itoa(va_arg(tab->args, int));
	if (!nbr)
		return (tab->error = 1, -1);
	nbr = ft_format_d_usingflags(nbr, tab);
	if (!nbr)
		return (tab->error = 1, -1);
	ft_addstr((const char *)nbr, tab);
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
