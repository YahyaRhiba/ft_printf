/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:27:20 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/03 16:40:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	i;

	lens = ft_strlen(src);
	if (!dst || !src)
		return (0);
	else if (!dstsize)
		return (lens);
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lens);
}

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	rtn = (char *)malloc(sizeof(char) * size);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, size);
	return (rtn);
}
