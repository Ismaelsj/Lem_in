/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:05:12 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 16:57:56 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_string(int nb, char *str)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	ft_bzero(ptr, nb + 1);
	ptr = ft_strncat(ptr, str, nb);
	if (str)
		free(str);
	return (ptr);
}

static char		*ft_number_nb(t_flag *tmp, char *str, int nb)
{
	char	*ptr;

	if (str[0] == '-')
	{
		ptr = ft_strjoin_free(ft_newstr(nb - (int)ft_strlen(str)
					+ 2, '0'), ft_strdup(str + 1));
		free(str);
		ptr[0] = '-';
	}
	else if (str[1] == 'x' || str[1] == 'X')
	{
		ptr = ft_strjoin_free(ft_newstr((nb - (int)ft_strlen(str)
					+ 2), '0'), ft_strdup(str + 2));
		free(str);
		if (tmp->specifier == 'X')
			ptr[1] = 'X';
		else
			ptr[1] = 'x';
	}
	else
		ptr = ft_strjoin_free(ft_newstr((nb
						- (int)ft_strlen(str)), '0'), str);
	return (ptr);
}

static int		ft_validtype(int c)
{
	int		i;
	char	*str;

	i = 0;
	if (c == 'd' || c == 'D' || c == 'i')
		return (2);
	str = "uUxXoOp";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_is_precision(t_flag *tmp, char *str, int nb)
{
	char	*ptr;

	if ((ft_validtype(tmp->specifier) == 2 && nb > ((int)ft_strlen(str)) - 1)
			|| (ft_validtype(tmp->specifier) == 1 && nb > (int)ft_strlen(str)))
		str = ft_number_nb(tmp, str, nb);
	else if ((tmp->specifier == 's' || tmp->specifier == 'S')
			&& (nb > 0) < (int)ft_strlen(str))
		str = ft_string(nb, str);
	else if (nb == 0 && ft_strcmp(str, "0") == 0 && tmp->specifier != 'p')
	{
		ptr = str;
		str = ft_newstr(0, '\0');
		free(ptr);
	}
	return (str);
}
