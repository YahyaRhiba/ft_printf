/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:10:22 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/01 01:04:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_s(char *s, t_print *tab)
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

char	*ft_mins_s(char *s, t_print *tab)
{
	char	*rtn;
	int		len;
	int		i;

	len = ft_strlen((const char *)s);
	if (len > tab->m_num)
		return (s);
	rtn = (char *)malloc(sizeof(char) * (tab->m_num + 1));
	if (!rtn)
		return (free(s), NULL);
	i = 0;
	while (i < len)
	{
		rtn[i] = s[i];
		i++;
	}
	while (i < tab->m_num)
		rtn[i++] = 32;
	rtn[i] = '\0';
	return (free(s), rtn);
}

char	*ft_zerospaces_s(char *s, int c, int t_len)
{
	char	*rtn;
	int		len;
	int		i;
	int		j;

	len = (int)ft_strlen((const char *)s);
	if (t_len < len)
		return (s);
	rtn = (char *)malloc(sizeof(char) * (t_len + 1));
	if (!rtn)
		return (free(s), NULL);
	i = 0;
	while (i < (t_len - len))
		rtn[i++] = c;
	j = 0;
	while (j < len)
		rtn[i++] = s[j++];
	rtn[i] = '\0';
	return (free(s), rtn);
}

char	*ft_format_s_usingflags(char *s, t_print *tab)
{
	if (tab->point == 1)
	{
		s = ft_precision_s(s, tab);
		if (!s)
			return (NULL);
	}
	if (tab->mines == 1)
	{
		s = ft_mins_s(s, tab);
		if (!s)
			return (NULL);
	}
	else if (tab->zero == 1)
	{
		s = ft_zerospaces_s(s, '0', tab->z_num);
		if (!s)
			return (NULL);
	}
	else if (tab->nbr == 1)
	{
		s = ft_zerospaces_s(s, 32, tab->n_nbr);
		if (!s)
			return (NULL);
	}
	return (s);
}
