/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:28:12 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/20 19:44:30 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_set_to_zero(t_flag *tmp)
{
	tmp->h = 0;
	tmp->hh = 0;
	tmp->l = 0;
	tmp->ll = 0;
	tmp->j = 0;
	tmp->z = 0;
}

char			*ft_check_length(char *format, int i, t_flag *tmp
		, va_list ap)
{
	while (format[i] != tmp->specifier && format[i])
	{
		ft_set_to_zero(tmp);
		if (format[i] == 'h' && format[i + 1] == 'h')
		{
			tmp->hh = 1;
			i++;
		}
		else if (format[i] == 'h')
			tmp->h = 1;
		else if (format[i] == 'l' && format[i + 1] == 'l')
		{
			tmp->ll = 1;
			i++;
		}
		else if (format[i] == 'l')
			tmp->l = 1;
		else if (format[i] == 'j')
			tmp->j = 1;
		else if (format[i] == 'z')
			tmp->z = 1;
		i++;
	}
	return (ft_get_string(tmp, ap));
}
