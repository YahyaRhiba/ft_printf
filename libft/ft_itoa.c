/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:08:14 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/21 23:34:06 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_crtn(int n, size_t len, char *rtn)
{
	while (n > 0)
	{
		rtn[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (rtn);
}

char	*ft_itoa(int n)
{
	char	*rtn;
	size_t	len;
	size_t	k;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(n);
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	k = 0;
	if (n < 0)
	{
		n = -n;
		rtn[0] = '-';
		k = 1;
	}
	rtn[len--] = '\0';
	rtn = ft_crtn(n, len, rtn);
	return (rtn);
}
