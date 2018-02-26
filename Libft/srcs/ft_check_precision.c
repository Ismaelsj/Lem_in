/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:33:41 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/20 19:45:00 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_precision(char const *format, int i)
{
	if (format[i] == '*')
		return (2);
	return (1);
}

char		*ft_check_precision(char *format, int i, t_flag *tmp,
		va_list ap)
{
	int		ret;

	ret = 0;
	if (format[i] == '.')
	{
		i++;
		ret = ft_precision(format, i);
	}
	if (ret == 1)
	{
		tmp->precision_nb = ft_atoi(format + i);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
		return (ft_check_length(format, i, tmp, ap));
	}
	else if (ret == 2)
	{
		tmp->precision_st = va_arg(ap, int);
		return (ft_check_length(format, i + 1, tmp, ap));
	}
	return (ft_check_length(format, i, tmp, ap));
}
