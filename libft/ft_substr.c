/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:27:20 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/09 08:20:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*rtn;

	if (!s)
		return (0);
	if ((size_t) start > ft_strlen(s))
		return (ft_strdup(""));
	rtn = (char *) malloc (sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (i < len)
	{
		rtn[i] = s[i + start];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
