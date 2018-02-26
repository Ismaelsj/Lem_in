/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:58:31 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/21 12:02:35 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int		ft_is_there_flags(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

static t_flag	*ft_t_flag(t_flag *tmp)
{
	if (tmp == NULL)
	{
		if (!(tmp = (t_flag*)malloc(sizeof(t_flag))))
			return (NULL);
		tmp->index = 0;
		tmp->bites_nb = 0;
	}
	tmp->specifier = -1;
	tmp->minus = -1;
	tmp->plus = -1;
	tmp->sharp = -1;
	tmp->space = -1;
	tmp->zero = -1;
	tmp->width_nb = -1;
	tmp->width_st = -1;
	tmp->precision_nb = -1;
	tmp->precision_st = -1;
	tmp->hh = -1;
	tmp->h = -1;
	tmp->ll = -1;
	tmp->l = -1;
	tmp->j = -1;
	tmp->z = -1;
	tmp->bzero = 0;
	return (tmp);
}

static int		ft_running(const char *format, t_flag *lst, char *str,
		va_list ap)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (format[i])
	{
		ft_t_flag(lst);
		if (format[i] == '%')
		{
			if ((j = ft_check_specifier(format + i + 1, &str, lst, ap)) == -1)
			{
				write(lst->fd, str, lst->index - k);
				return (-1);
			}
			i += j + 1 + (k = 0);
		}
		else
		{
			ft_putbuffer(ft_strcdup(format + i, '%'), str, lst);
			i += (k = ft_strclen(format + i, '%'));
		}
	}
	write(lst->fd, str, lst->index);
	return (lst->bites_nb);
}

int				ft_printf_fd(int fd, const char *format, ...)
{
	va_list		ap;
	int			i;
	char		str[TAILLE_MAX_BUFF];
	t_flag		*lst;
	static int	non;

	va_start(ap, format);
	lst = NULL;
	if (!(format))
		return (0);
	else if (ft_is_there_flags(format) == 0)
		return (write(fd, format, ft_strlen(format)));
	if (!(lst = ft_t_flag(lst)))
		return (-1);
	lst->fd = fd;
	ft_bzero(str, TAILLE_MAX_BUFF);
	i = ft_running(format, lst, str, ap);
	free(lst);
	va_end(ap);
	if (non == -1)
		return (non);
	else
		non = i;
	return (i);
}
