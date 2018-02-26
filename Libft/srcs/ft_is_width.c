/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:02:32 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 16:58:13 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_widthzero(int nb, char *str, t_flag *tmp)
{
	char	c;
	char	*ptr;

	if (tmp->specifier == 'c' || tmp->specifier == 'C')
		nb--;
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		c = str[0];
		ptr = ft_strjoin_free(ft_newstr(nb - ft_strlen(str) + 1, '0')
				, ft_strdup(str + 1));
		free(str);
		ptr[0] = c;
	}
	else if (str[1] == 'x' || str[1] == 'X')
	{
		ptr = ft_strjoin_free(ft_newstr(nb - ft_strlen(str) + 2, '0')
				, ft_strdup(str + 2));
		free(str);
		ptr[1] = 'x';
	}
	else
		ptr = ft_strjoin_free(ft_newstr(nb - ft_strlen(str), '0'), str);
	return (ptr);
}

static int		ft_undifined(t_flag *tmp)
{
	if (tmp->specifier == 'S' || tmp->specifier == 's'
			|| tmp->specifier == 'c' || tmp->specifier == 'c'
			|| tmp->specifier == '%')
		return (1);
	return (0);
}

char			*ft_is_width(t_flag *tmp, int nb, char *str)
{
	if (tmp->bzero == 1 && tmp->minus == '-')
		nb -= 1;
	if (tmp->minus > 0)
		str = ft_strjoin_free(str, ft_newstr(nb - ft_strlen(str), ' '));
	else if (tmp->zero == -1)
		str = ft_strjoin_free(ft_newstr(nb - ft_strlen(str) - tmp->bzero, ' ')
				, str);
	else if (tmp->zero > 0 && ((tmp->precision_nb == -1
			&& tmp->precision_st == -1) || ft_undifined(tmp) == 1))
		str = ft_widthzero(nb, str, tmp);
	else if ((int)ft_strlen(str) < nb)
	{
		str = ft_strjoin_free(ft_newstr(nb - ft_strlen(str), ' ')
				, ft_strdup(str));
	}
	return (str);
}
