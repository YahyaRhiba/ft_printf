/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:04:46 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/01 03:39:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_c(t_print *tab, int c)
{
	if (tab->mines == 1)
	{
		tab->len += write(1, &c, 1);
		ft_print_char(32, tab->width - 1, tab);
	}
	else if (tab->zero == 1)
	{
		ft_print_char('0', tab->width - 1, tab);
		tab->len += write(1, &c, 1);
	}
	else if (tab->width == 1)
	{
		ft_print_char(32, tab->width - 1, tab);
		tab->len += write(1, &c, 1);
	}
	else
		tab->len += write(1, &c, 1);
}
