/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:06:09 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/29 15:33:37 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_negative(char *base, int nb, int nb_base)
{
	int		i;
	int		j;
	char	*str;

	i = -nb;
	nb = -nb;
	j = 1;
	while (i >= nb_base)
	{
		i /= nb_base;
		j++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	str[j + 1] = '\0';
	while (j > 0)
	{
		str[j] = base[nb % nb_base];
		nb /= nb_base;
		j--;
	}
	str[j] = '-';
	return (str);
}

char		*ft_itoa_base(int nb, int nb_base)
{
	int		i;
	int		j;
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	j = 1;
	i = nb;
	if (nb < 0 && nb_base == 10)
		return (ft_negative(base, nb, nb_base));
	while (i >= nb_base)
	{
		i /= nb_base;
		j++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (j))))
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
