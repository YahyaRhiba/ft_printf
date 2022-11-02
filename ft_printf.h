/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:27:27 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/02 21:20:17 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define PNULL "(null)"
# define UPPRX "0X"
# define LWPRX "0x"
# define UPHEX "0123456789ABCDEF"
# define LWHEX "0123456789abcdef"

typedef struct s_print
{
	va_list	args;
	int		error;
	int		width;
	int		mines;
	int		zero;
	int		point;
	int		hash;
	int		space;
	int		plus;
	int		w_nbr;
	int		p_num;
	int		buflen;
	char	*buff;
}			t_print;

void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
int			ft_isnum(int c);
char		*ft_itoa(long long n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

char		*ft_converthex(unsigned long n, const char *base);
int			ft_skip_num(const char *format, int i);
char		*ft_mins_s(char *s, t_print *tab);

int			ft_printf(const char *format, ...);

int			ft_format(const char *format, int i, t_print *tab);

void		ft_init_tab(t_print *tab);

int			ft_addchar(t_print *tab, char c);
int			ft_addnchar(char c, int len, t_print *tab);
int			ft_addstr(const char *s, t_print *tab);

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
char		*ft_format_d_usingflags(char *nbr, t_print *tab);
int			ft_format_u(t_print *tab);
int			ft_format_x(t_print *tab, const char *base, const char *suff);

#endif
