/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:27:27 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/01 17:59:17 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define P_NULL "(null)"

typedef struct s_print
{
	va_list	args;
	int		len;
	int		width;
	int		mines;
	int		zero;
	int		point;
	int		hash;
	int		space;
	int		plus;
	int		w_nbr;
	int		p_num;
}			t_print;

int			ft_atoi(const char *str);
char		*ft_itoa(int nbr);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_isnum(int c);
int			ft_skip_num(const char *format, int i);
char		*ft_mins_s(char *s, t_print *tab);

int			ft_printf(const char *format, ...);
void		ft_print_char(char c, int len, t_print *tab);
int			ft_print_str(const char *str, t_print *tab);

void		ft_init_tab(t_print *tab);

int			ft_check_flags(const char *format, int index, t_print *to_print);

int			ft_fcheck_width(const char *format, int *i, t_print *tab);
int			ft_fcheck_zero(const char *format, int *i, t_print *tab);
int			ft_fcheck_mins(const char *format, int *i, t_print *tab);
int			ft_fcheck_point(const char *format, int *i, t_print *tab);
int			ft_fcheck_hash(const char *format, int *i, t_print *tab);
int			ft_fcheck_space(const char *format, int *i, t_print *tab);
int			ft_fcheck_plus(const char *format, int *i, t_print *tab);

int			ft_check_format(const char *format, int i, t_print *tab);

void		ft_format_c(t_print *tab, int c);
int			ft_format_s(t_print *tab);
char		*ft_format_s_usingflags(char *s, t_print *tab);
int			ft_format_d(t_print *tab);

#endif
