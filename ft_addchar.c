/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:04:14 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 02:46:03 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addnchar(char c, int len, t_print *tab)
{
	int		i;
	char	*s;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (tab->error = 1, -1);
	i = 0;
	while (i < len)
		s[i++] = c;
	s[i] = '\0';
	ft_addstr((const char *)s, tab);
	free(s);
	return (len);
}

int	ft_addchar(t_print *tab, char c)
{
	int		i;
	char	*new;

	new = (char *)ft_calloc((ft_strlen(tab->buff) + 2), sizeof(char));
	if (!new)
		return (tab->error = 1, -1);
	i = 0;
	while (tab->buff[i])
	{
		new[i] = tab->buff[i];
		i++;
	}
	new[i] = c;
	free(tab->buff);
	tab->buff = new;
	return (1);
}
