/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:38:19 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 16:08:47 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag(char c)
{
	int		i;
	char	*fg;

	i = 0;
	fg = "-+ #0";
	while (fg[i] != '\0' && fg[i] != c)
		i++;
	if (fg[i] == '\0')
		return (0);
	return (c);
}

char		*ft_check_flag(char *format, t_flag *tmp, va_list ap)
{
	int		i;
	int		ret;

	i = 0;
	while (ft_flag(format[i]) != 0 && format[i])
	{
		ret = ft_flag(format[i]);
		if (ret == '-')
			tmp->minus = '-';
		else if (ret == '+')
			tmp->plus = '+';
		else if (ret == ' ')
			tmp->space = ' ';
		else if (ret == '#')
			tmp->sharp = '#';
		else if (ret == '0')
			tmp->zero = '0';
		i++;
	}
	return (ft_check_width(format, i, tmp, ap));
}
