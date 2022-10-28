/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fone_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:04:46 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/28 02:12:50 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

    flags

        -  : work
        0  : work ignored if - exist
        .  : don't
        #  : don't
       ' ' : dont't
        +  : dont't

*/

void    ft_format_c(t_print *tab)
{
    char c;

    c = va_arg(tab->args, int);
    if (tab->mines == 1)
    {
        tab->len += write(1, &c, 1);
        ft_print(' ', tab->m_num - 1, tab);
    }
}
