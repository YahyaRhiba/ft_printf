/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:00:03 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/08 13:24:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_b_zero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *) s;
	i = 0;
	while (i < n)
		tmp[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = malloc(size * count);
	if (!rtn)
		return (NULL);
	ft_b_zero(rtn, size * count);
	return (rtn);
}
