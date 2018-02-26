/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:06:14 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/14 16:36:38 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *i;
	char j;

	i = (char*)s;
	j = (char)c;
	while (*i != '\0')
	{
		if (*i == j)
			return (i);
		i++;
	}
	if (*i == j)
		return (i);
	return (NULL);
}
