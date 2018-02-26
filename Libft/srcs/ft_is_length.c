/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:19:04 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 15:20:48 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_signed(va_list ap, t_flag *tmp)
{
	char	*str;

	str = NULL;
	if (tmp->hh == 1)
		str = ft_lltoa((char)va_arg(ap, long long));
	else if (tmp->h == 1)
		str = ft_lltoa((short int)va_arg(ap, long long));
	else if (tmp->l == 1)
		str = ft_lltoa((long)va_arg(ap, long long));
	else if (tmp->ll == 1)
		str = ft_lltoa((long long)va_arg(ap, intmax_t));
	else if (tmp->j == 1)
		str = ft_lltoa((intmax_t)va_arg(ap, intmax_t));
	else if (tmp->z == 1)
		str = ft_lltoa((size_t)va_arg(ap, long long));
	return (str);
}

static char	*ft_get_unsigned(va_list ap, t_flag *tmp, int base)
{
	char	*str;

	str = NULL;
	if (tmp->hh == 1)
		str = ft_umaxtoa_base((unsigned char)va_arg(ap, intmax_t), base);
	else if (tmp->h == 1)
		str = ft_umaxtoa_base((unsigned short int)va_arg(ap, intmax_t), base);
	else if (tmp->l == 1)
		str = ft_umaxtoa_base((unsigned long)va_arg(ap, intmax_t), base);
	else if (tmp->ll == 1)
		str = ft_umaxtoa_base((unsigned long long)va_arg(ap, intmax_t), base);
	else if (tmp->j == 1)
		str = ft_umaxtoa_base((uintmax_t)va_arg(ap, intmax_t), base);
	else if (tmp->z == 1)
		str = ft_umaxtoa_base((size_t)va_arg(ap, intmax_t), base);
	return (str);
}

static char	*ft_wint_t(va_list ap, t_flag *tmp)
{
	char *str;

	str = NULL;
	if (tmp->l == 1)
		str = ft_char_uni(va_arg(ap, wint_t), tmp);
	return (str);
}

static char	*ft_wchar_t(va_list ap, t_flag *tmp)
{
	char *str;

	str = NULL;
	if (tmp->l == 1)
		str = ft_str_uni(va_arg(ap, wchar_t*), tmp);
	return (str);
}

char		*ft_length(va_list ap, t_flag *tmp)
{
	char *str;

	str = NULL;
	if (tmp->specifier == 'd' || tmp->specifier == 'i')
		str = ft_get_signed(ap, tmp);
	else if (tmp->specifier == 'u')
		str = ft_get_unsigned(ap, tmp, 10);
	else if (tmp->specifier == 'o')
		str = ft_get_unsigned(ap, tmp, 8);
	else if (tmp->specifier == 'x' || tmp->specifier == 'X')
		str = ft_get_unsigned(ap, tmp, 16);
	else if (tmp->specifier == 'c')
		str = ft_wint_t(ap, tmp);
	else if (tmp->specifier == 's')
		str = ft_wchar_t(ap, tmp);
	return (str);
}
