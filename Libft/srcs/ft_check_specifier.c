/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:37:19 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 15:04:23 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_specifier(char c)
{
	int		i;
	char	*sp;

	i = 0;
	sp = "sSpdDioOuUxXcC%";
	while (sp[i] != '\0' && sp[i] != c)
		i++;
	if (sp[i] == '\0')
		return (0);
	else
		return ((int)sp[i]);
}

int				ft_check_specifier(char const *format, char **str, t_flag *tmp,
		va_list ap)
{
	int		j;
	int		ret;
	char	*tp;

	j = 0;
	while (format[j] != '\0' && (ret = ft_specifier(format[j])) == 0)
		j++;
	if (format[j] == '\0')
		return (0);
	tmp->specifier = ret;
	if (ret == 'p')
		tmp->sharp = '#';
	if (!(tp = ft_strcdup(format, ret)))
		return (-1);
	if (ft_putbuffer(ft_check_flag(tp, tmp, ap), *str, tmp) == -1)
	{
		free(tp);
		return (-1);
	}
	free(tp);
	if (*str == NULL)
		return (-1);
	if (format[j] == '\0')
		return (j);
	return (j + 1);
}
