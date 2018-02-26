/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uni.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:50:05 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 16:51:26 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_uni(wint_t c, t_flag *tmp)
{
	char str[2];

	ft_bzero(str, 2);
	if ((c >= 0xd800 && c <= 0xDfff) || (c < 0))
		return (NULL);
	if (c <= 255)
	{
		if (c == 0)
			tmp->bzero = 1;
		str[0] = (char)c;
	}
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
		return (ft_put_two(c));
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
		return (ft_put_three(c));
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
		return (ft_put_four(c));
	else
		return (NULL);
	return (ft_strdup(str));
}

static int		ft_pre_uni(wchar_t *str, int *nb)
{
	int		j;
	int		a;
	int		i;

	a = 0;
	i = 0;
	while (str[i] && a < *nb)
	{
		j = 0;
		if (str[i] <= 255)
			j = 1;
		else if (str[i] <= 0x7FF)
			j = 2;
		else if (str[i] <= 0xFFFF)
			j = 3;
		else if (str[i] <= 0x10FFFF)
			j = 4;
		if ((a + j) <= *nb)
			a += j;
		i++;
	}
	*nb = a;
	return (1);
}

char			*ft_str_uni(wchar_t *str, t_flag *tmp)
{
	char	*s;
	int		i;
	int		*nb;

	i = 0;
	if (str == NULL)
	{
		tmp->specifier = 's';
		return (NULL);
	}
	if (tmp->precision_nb > 0 || tmp->precision_st > 0)
	{
		if (tmp->precision_nb >= 0)
			nb = &tmp->precision_nb;
		else if (tmp->precision_st >= 0)
			nb = &tmp->precision_st;
		else
			nb = NULL;
		ft_pre_uni(str, nb);
		s = ft_uni_str_pre(str, tmp, *nb);
	}
	else
		s = ft_uni_str(str, tmp);
	return (s);
}

char			*ft_char_uni(wint_t c, t_flag *tmp)
{
	char	*str;

	str = ft_uni(c, tmp);
	return (str);
}
