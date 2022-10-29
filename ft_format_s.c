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

	len = ft_strlen((const char *)s);
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

char *ft_mins_s(char *r, t_print *tab)
{
	char *rtn;
	int len;
	int	i;

	len = ft_strlen((const char *)r);
	if (len > tab->m_num)
		return (r);
	rtn = (char *)malloc(sizeof(char) * (tab->m_num + 1));
	if (!rtn)
		return (free(r), NULL);
	i = 0;
	while (i < len)
	{
		rtn[i] = r[i];
		i++;
	}
	while (i < tab->m_num)
		rtn[i++] = 32;
	rtn[i] = '\0';
	return (free(r), rtn);
}

char *ft_zeros_s(char *r, t_print *tab)
{
	char *rtn;
	int len;
	int i;
	int j;

	len = ft_strlen((const char *)r);
	if (tab->z_num < len)
		return (r);
	rtn = (char *)malloc(sizeof(char) * (tab->z_num + 1));
	if (!rtn)
		return (free(r), NULL);
	i = 0;
	while (i < (tab->z_num - len))
		rtn[i++] = '0';
	j = 0;
	while(j < len)
		rtn[i++] = r[j++];
	rtn[i] = '\0';
	return (free(r), rtn);
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
	if (tab->mines == 1)
	{
		r = ft_mins_s(r, tab);
		if (!r)
			return ;
	}
	if (tab->zero == 1 && tab->mines == 0)
	{
		r = ft_zeros_s(r, tab);
		if (!r)
			return ;
	}
	tab->len += write(1, r, ft_strlen(r));
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
