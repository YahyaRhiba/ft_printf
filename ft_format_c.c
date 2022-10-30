/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:04:46 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/30 19:00:51 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_c(t_print *tab, int c)
{
	if (tab->mines == 1)
	{
		tab->len += write(1, &c, 1);
		ft_print(' ', tab->m_num - 1, tab);
	}
	else if (tab->zero == 1)
	{
		ft_print('0', tab->z_num - 1, tab);
		tab->len += write(1, &c, 1);
	}
	else if (tab->nbr == 1)
	{
		ft_print(32, tab->n_nbr - 1, tab);
		tab->len += write(1, &c, 1);
	}
	else
		tab->len += write(1, &c, 1);
}
