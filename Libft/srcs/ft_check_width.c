/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:55:27 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/20 19:45:11 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_width(char const *format, int i)
{
	if (format[i] >= '1' && format[i] <= '9')
		return (1);
	else if (format[i] == '*')
		return (2);
	return (0);
}

char				*ft_check_width(char *format, int i, t_flag *tmp
		, va_list ap)
{
	int		ret;

	ret = ft_width(format, i);
	if (ret == 1)
	{
		tmp->width_nb = ft_atoi(format + i);
		while (ft_isdigit(format[i]) == 1)
			i++;
		return (ft_check_precision(format, i, tmp, ap));
	}
	else if (ret == 2)
	{
		tmp->width_st = va_arg(ap, int);
		return (ft_check_precision(format, i + 1, tmp, ap));
	}
	return (ft_check_precision(format, i, tmp, ap));
}
