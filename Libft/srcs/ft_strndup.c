/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:39:35 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/14 11:21:27 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t c)
{
	unsigned int	j;
	char			*str;

	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	while (j < c)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
