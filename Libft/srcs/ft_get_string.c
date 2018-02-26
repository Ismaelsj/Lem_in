/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:26:12 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 17:22:19 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ctype(char *str, int c, t_flag *tmp)
{
	str = ft_strnew(1);
	str[0] = c;
	if (c == '\0')
		tmp->bzero = 1;
	return (str);
}

static char		*ft_strtype(char *str, char *j)
{
	char	*ptr;

	str = ft_strnew(0);
	ptr = str;
	str = ft_strjoin(str, j);
	free(ptr);
	return (str);
}

static void		ft_type(char c, va_list ap, char **str, t_flag *tmp)
{
	if (c == 's' && ((*str = va_arg(ap, char*)) != NULL))
		*str = ft_strdup(*str);
	else if (c == 'S')
		*str = ft_str_uni(va_arg(ap, wchar_t*), tmp);
	else if (c == 'p')
		*str = ft_umaxtoa_base(va_arg(ap, unsigned long long), 16);
	else if (c == 'd' || c == 'i')
		*str = ft_lltoa(va_arg(ap, int));
	else if (c == 'D')
		*str = ft_lltoa(va_arg(ap, long long));
	else if (c == 'U')
		*str = ft_umaxtoa_base(va_arg(ap, unsigned long), 10);
	else if (c == 'u')
		*str = ft_umaxtoa_base(va_arg(ap, unsigned int), 10);
	else if (c == 'o')
		*str = ft_umaxtoa_base(va_arg(ap, unsigned int), 8);
	else if (c == 'O')
		*str = ft_umaxtoa_base(va_arg(ap, unsigned long), 8);
	else if (c == 'x' || c == 'X')
		*str = ft_umaxtoa_base(va_arg(ap, unsigned int), 16);
	else if (c == 'c')
		*str = ft_ctype(*str, va_arg(ap, int), tmp);
	else if (c == 'C')
		*str = ft_char_uni(va_arg(ap, wint_t), tmp);
}

static int		ft_isbig(t_flag *tmp)
{
	if (tmp->specifier == 's' && tmp->l == 1)
		return (1);
	else if (tmp->specifier == 'c' && tmp->l == 1)
		return (1);
	else
		return (0);
}

char			*ft_get_string(t_flag *tmp, va_list ap)
{
	char	*str;

	if (tmp->specifier == '%')
		str = ft_newstr(1, '%');
	else if ((str = ft_length(ap, tmp)) == NULL && ft_isbig(tmp) == 0)
		ft_type(tmp->specifier, ap, &str, tmp);
	if (str == NULL && tmp->specifier == 's' && ft_isbig(tmp) == 0)
		str = ft_strtype(str, "(null)");
	if (tmp->precision_nb > -1 && str != NULL)
		str = ft_is_precision(tmp, str, tmp->precision_nb);
	else if (tmp->precision_st > -1 && str != NULL)
		str = ft_is_precision(tmp, str, tmp->precision_st);
	if (tmp->sharp > -1 && (ft_diffbase(tmp->specifier) == 1))
		str = ft_sharp(tmp->specifier, str, tmp);
	if (tmp->plus > -1 && (ft_decimal(tmp->specifier) == 1) && str[0] != '-')
		str = ft_strjoin_free(ft_newstr(1, '+'), str);
	if (ft_space_con(tmp) && str[0] != '-')
		str = ft_strjoin_free(ft_newstr(1, ' '), str);
	if (tmp->width_nb > -1 && str && (int)ft_strlen(str) < tmp->width_nb)
		str = ft_is_width(tmp, tmp->width_nb, str);
	else if (tmp->width_st > -1 && str && (int)ft_strlen(str) < tmp->width_st)
		str = ft_is_width(tmp, tmp->width_st, str);
	if (tmp->specifier == 'X')
		str = ft_strupcase(str);
	return (str);
}
