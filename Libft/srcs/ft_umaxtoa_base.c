/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:42:07 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/20 16:25:27 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char		*ft_umaxtoa_base(uintmax_t nb, uintmax_t nb_base)
{
	uintmax_t				i;
	intmax_t				j;
	char					*str;
	char					*base;

	base = "0123456789abcdef";
	j = 1;
	i = nb;
	while (i >= nb_base)
	{
		i /= nb_base;
		j++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	str[j--] = '\0';
	while (j >= 0)
	{
		str[j] = base[nb % nb_base];
		nb /= nb_base;
		j--;
	}
	return (str);
}
