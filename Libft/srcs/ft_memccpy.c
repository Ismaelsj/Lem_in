/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:15:39 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/14 16:41:16 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*i;
	char	*j;
	int		a;

	i = (char*)dst;
	j = (char*)src;
	a = 0;
	while (n--)
	{
		i[a] = j[a];
		if (i[a] == (char)c)
		{
			a++;
			return (dst + a);
		}
		a++;
	}
	return (NULL);
}
