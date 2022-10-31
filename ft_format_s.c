/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:14:56 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/31 02:19:32 by yrhiba           ###   ########.fr       */
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

char	*ft_mins_s(char *r, t_print *tab)
{
	char	*rtn;
	int		len;
	int		i;

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

char	*ft_zerospaces_s(char *r, int c, int t_len)
{
	char	*rtn;
	int		len;
	int		i;
	int		j;

	len = (int) ft_strlen((const char *)r);
	if (t_len < len)
		return (r);
	rtn = (char *)malloc(sizeof(char) * (t_len + 1));
	if (!rtn)
		return (free(r), NULL);
	i = 0;
	while (i < (t_len - len))
		rtn[i++] = c;
	j = 0;
	while (j < len)
		rtn[i++] = r[j++];
	rtn[i] = '\0';
	return (free(r), rtn);
}

int	ft_format_s(t_print *tab)
{
	char	*r;

	r = ft_strdup((const char *)va_arg(tab->args, char *));
	if (!r)
		return (ft_print_null(tab));
	if (tab->point == 1)
	{
		r = ft_precision_s(r, tab);
		if (!r)
			return (ft_print_null(tab));
	}
	if (tab->mines == 1)
	{
		r = ft_mins_s(r, tab);
		if (!r)
			return (ft_print_null(tab));
	}
	if (tab->zero == 1 && tab->mines == 0)
	{
		r = ft_zerospaces_s(r, '0', tab->z_num);
		if (!r)
			return (ft_print_null(tab));
	}
	if (tab->nbr == 1 && tab->mines == 0 && tab->zero == 0)
	{
		r = ft_zerospaces_s(r, 32, tab->n_nbr);
		if (!r)
			return (ft_print_null(tab));
	}
	tab->len += write(1, r, ft_strlen(r));
	return (free(r), 0);
}
