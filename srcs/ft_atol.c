/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:27:08 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/08 15:28:13 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

long		ft_atol(const char *str)
{
	long i;
	long j;
	long k;

	i = 0;
	j = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		j = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	k = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		k = k * 10 + (str[i] - 48);
		i++;
	}
	if (j == 1)
		k = -k;
	return (k);
}
