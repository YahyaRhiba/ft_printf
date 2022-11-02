/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:04:14 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 01:49:00 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_addchar(t_print *tab, char *c)
{
	int		i;
	char	*new;

	new = (char *)ft_calloc((ft_strlen(tab->buff) + 2), sizeof(char));
	if (!new)
		return (tab->error = 1, -1);
	i = -1;
	while ((tab->buff)[++i])
		new[i] = (tab->buff)[i];
	new[i] = c;
	free(tab->buff);
	tab->buff = new;
	return (1);
}
