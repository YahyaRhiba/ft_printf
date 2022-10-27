/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:45:37 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/27 18:47:13 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_tab(t_print *tab)
{
	tab->len = 0;
	tab->mines = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->hash = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->z_num = 0;
	tab->p_num = 0;
	tab->m_num = 0;
}
