/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:01:47 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/28 02:10:03 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_skip_num(const char *format, int i)
{
	while (format[i] <= '9' && format[i] >= '0')
		i++;
	return (i);
}

static int	ft_fcheck_zero(const char *format, int *i, t_print *tab)
{
	if (format[*i] == '0')
	{
		tab->zero = 1;
		*i = *i + 1;
		tab->z_num = ft_atoi(format + *i);
		*i = ft_skip_num(format, *i);
	}
	return (*i);
}

static int	ft_fcheck_mins(const char *format, int *i, t_print *tab)
{
	if (format[*i] == '-')
	{
		tab->mines = 1;
		*i = *i + 1;
		tab->m_num = ft_atoi(format + *i);
		*i = ft_skip_num(format, *i);
	}
	return (*i);
}

static int	ft_fcheck_point(const char *format, int *i, t_print *tab)
{
	if (format[*i] == '.')
	{
		tab->point = 1;
		*i += 1;
		tab->p_num = ft_atoi(format + *i);
		*i = ft_skip_num(format, *i);
	}
	return (*i);
}

int	ft_check_flags(const char *format, int i, t_print *tab)
{
	ft_fcheck_zero(format, &i, tab);
	ft_fcheck_mins(format, &i, tab);
	ft_fcheck_point(format, &i, tab);
	if (tab->point || tab->zero || tab->mines)
		return (i);
	if (format[i] == '#')
	{
		tab->hash = 1;
		return (i + 1);
	}
	if (format[i] == 32)
	{
		tab->space = 1;
		return (i + 1);
	}
	if (format[i] == '+')
	{
		tab->plus = 1;
		return (i + 1);
	}
	return (i);
}
