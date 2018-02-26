/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:03:58 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/21 11:07:00 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include "libft.h"
# define TAILLE_MAX_BUFF 80
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct	s_flag
{
	int			specifier;
	int			minus;
	int			plus;
	int			space;
	int			sharp;
	int			zero;
	int			width_nb;
	int			width_st;
	int			precision_nb;
	int			precision_st;
	int			hh;
	int			h;
	int			ll;
	int			l;
	int			j;
	int			z;
	int			bzero;
	int			index;
	int			bites_nb;
	int			fd;
}				t_flag;

int				ft_byte_nb(int i);
char			*ft_put_two(wint_t c);
char			*ft_put_three(wint_t c);
char			*ft_put_four(wint_t c);
int				ft_space_con(t_flag *tmp);
char			*ft_uni_str_pre(wchar_t *str, t_flag *tmp, int nb);
char			*ft_uni_str(wchar_t *str, t_flag *tmp);
char			*ft_uni(wint_t c, t_flag *tmp);
int				ft_putbuffer(char *str, char *buff, t_flag *tmp);
int				ft_decimal(int c);
int				ft_diffbase(int c);
char			*ft_length(va_list ap, t_flag *tmp);
char			*ft_umaxtoa_base(uintmax_t nb, uintmax_t nb_base);
char			*ft_lltoa(long long nb);
char			*ft_str_uni(wchar_t *str, t_flag *tmp);
char			*ft_char_uni(wint_t c, t_flag *tmp);
char			*ft_sharp(int spe, char *str, t_flag *tmp);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_is_width(t_flag *tmp, int nb, char *str);
char			*ft_is_precision(t_flag *tmp, char *str, int nb);
char			*ft_newstr(int size, char c);
char			*ft_get_string(t_flag *tmp, va_list ap);
char			*ft_check_length(char *format, int i, t_flag *tmp, va_list ap);
char			*ft_check_precision(char *format, int i, t_flag *tmp,
		va_list ap);
char			*ft_check_width(char *format, int i, t_flag *tmp, va_list ap);
char			*ft_check_flag(char *format, t_flag *tmp, va_list ap);
int				ft_check_specifier(char const *format, char **str, t_flag *tmp,
		va_list ap);
int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);
#endif
