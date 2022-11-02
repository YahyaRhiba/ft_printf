/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:46:22 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 01:43:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str, t_print *tab)
{
	tab->len += write(1, str, ft_strlen(str));
	return (0);
}

void	ft_print_char(char c, int len, t_print *tab)
{
	int		i;
	char	*s;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return ;
	i = 0;
	while (i < len)
		s[i++] = c;
	s[i] = '\0';
	ft_print_str((const char *)s, tab);
	free(s);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		rtn;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab || !format)
		return (free(tab), -1);
	tab->buff = (char *)ft_calloc(1, sizeof(char));
	if (!tab->buff)
		return (free(tab), -1);
	va_start(tab->args, format);
	rtn = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			rtn += ft_format(format, &i, tab);
		else
			rtn += ft_addchar(tab, format + i);
		if (tab->error == 1)
			return (free(tab->buff), free(tab), -1);
	}
	return (va_end(tab->args), free(tab->buff), free(tab), rtn);
}
