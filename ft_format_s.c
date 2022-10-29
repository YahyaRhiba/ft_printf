/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:14:56 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/29 16:30:20 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision_s(char *s, t_print *tab)
{
	int		len;
	int		i;
	char	*rtn;

	len = ft_strlen(s);
	if (len < tab->p_num)
		return (s);
	rtn = (char *)malloc(sizeof(char) * (tab->p_num + 1));
	if (!rtn)
		return (free(s), NULL);
	i = 0;
	while (i < tab->p_num)
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
	return (free(s), rtn);
}

void	ft_format_s(t_print *tab)
{
	char	*r;

	r = ft_strdup((const char *)va_arg(tab->args, char *));
	if (!r)
		return ;
	if (tab->point == 1)
	{
		r = ft_precision_s(r, tab);
		if (!r)
			return ;
	}
}

/*

    flags for s

        -  : work second
        0  : work ignored if - exist
        .  : work first of all
        #  : 
       ' ' : 
        +  : 

*/
