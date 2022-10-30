/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:27:27 by yrhiba            #+#    #+#             */
/*   Updated: 2022/10/30 15:00:32 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	int		len;
	int		mines;
	int		zero;
	int		point;
	int		hash;
	int		space;
	int		plus;
	int		z_num;
	int		p_num;
	int		m_num;
}			t_print;

int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

int			ft_printf(const char *format, ...);
void		ft_print(char c, int i, t_print *tab);

void		ft_init_tab(t_print *tab);

int			ft_check_flags(const char *format, int index, t_print *to_print);

int			ft_fcheck_zero(const char *format, int *i, t_print *tab);
int			ft_fcheck_mins(const char *format, int *i, t_print *tab);
int			ft_fcheck_point(const char *format, int *i, t_print *tab);
int			ft_fcheck_hash(const char *format, int *i, t_print *tab);
int			ft_fcheck_space(const char *format, int *i, t_print *tab);
int			ft_fcheck_plus(const char *format, int *i, t_print *tab);

int			ft_check_format(const char *format, int old_i, int new_i,
				t_print *tab);

void		ft_format_c(t_print *tab, int c);
void		ft_format_s(t_print *tab);

#endif
