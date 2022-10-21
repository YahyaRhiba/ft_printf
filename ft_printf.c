/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:28:07 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/21 23:44:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_printf_check(char c, va_list *args, int rtn)
{
    char    *s;
    int     d;

    if (c == 'd' || c == 'i')
    {
        d = va_arg(*args, int);
        rtn += ft_nbrlen(d);
        ft_putnbr_fd(d, 1);
    }
    else if (c == 'c')
    {
        ft_putchar_fd(va_arg(*args, int), 1);
        rtn++;
    }
    else if (c == 's')
    {
        s = va_arg(*args, char *);
        rtn += (int)ft_strlen((const char *)s);
        ft_putstr_fd(s, 1);
    }
    return (rtn);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int     i;
    int     rtn;

    rtn = 0;
    va_start(args, str);
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            rtn = ft_printf_check(str[i], &args, rtn);
            if (str[i + 1] != '\0')
                i++;
        }
        else
        {
            ft_putchar_fd(str[i], 1);
            rtn++;
        }
        i++;
    }
    return (va_end(args), rtn);
}
