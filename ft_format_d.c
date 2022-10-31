/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:38:18 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/31 16:57:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_d(t_print *tab)
{
    int d;

    d = va_arg(tab->args, int);

}

/*

	HASH	: NO
	SPACE 	: YES IGNORED IF + EXIST
	PLUS	: YES
	MINS	: YES
	WIDTH	: YES
	ZEROS	: YES IGNORED IF PRES OR MINS EXIST
	PRECS	: YES

*/