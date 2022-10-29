/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:14:56 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/29 14:51:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_s(t_print *tab)
{
	char	*s;
	char	*r;

	s = va_arg(tab->args, char *);
	r = ft_strdup((const char *)s);
	if (!r)
		return ;
	if (tab->point == 1)
	{
		r = ft_per_s(s, tab);
	}
}

/*

    flags for s

        -  : work 
        0  : work ignored if - existe
        .  : 
        #  : 
       ' ' : 
        +  : 

*/
