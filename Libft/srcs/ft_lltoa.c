/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:50:34 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/20 19:47:12 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_filit(int signe, long long i, long long n, char *str)
{
	unsigned long long nb;

	nb = (unsigned long long)n;
	str[i + 1] = '\0';
	while (i > 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	if (signe == 1)
		str[i] = '-';
	else
		str[i] = nb + 48;
}

char		*ft_lltoa(long long n)
{
	long long			i;
	unsigned long long	j;
	int					a;
	char				*str;

	i = 0;
	a = 0;
	if (n < 0)
	{
		n = -n;
		a = 1;
		i++;
	}
	j = (unsigned long long)n;
	while (j >= 10)
	{
		i++;
		j = j / 10;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str)
		ft_filit(a, i, n, str);
	return (str);
}
