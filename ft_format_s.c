/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:14:56 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/31 03:41:36 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_format_s(t_print *tab)
{
	char	*s;

	s = ft_strdup((const char *)va_arg(tab->args, char *));
	if (!s)
		return (ft_print_str(P_NULL, tab));
	s = ft_format_s_usingflags(s, tab);
	if (!s)
		return (ft_print_str(P_NULL, tab));
	ft_print_str((const char *)s, tab);
	return (free(s), 0);
}
