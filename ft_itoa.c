/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:08:14 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/01 01:44:50 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nbrlen(long n)
{
	size_t	nlen;

	nlen = 0;
	if (n < 0)
	{
		nlen++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		nlen++;
	}
	return (nlen);
}

static char	*ft_crtn(long n, size_t len, char *rtn)
{
	while (n > 0)
	{
		rtn[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (rtn);
}

char	*ft_itoa(int nbr)
{
	char	*rtn;
	size_t	len;
	long	n;

	n = nbr;
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(n);
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		rtn[0] = '-';
	}
	rtn[len--] = '\0';
	return (ft_crtn(n, len, rtn));
}
