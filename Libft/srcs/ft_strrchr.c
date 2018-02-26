/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:19:06 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/20 13:18:31 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;
	char	j;
	size_t	k;

	i = (char*)s;
	j = (char)c;
	k = 0;
	while (i[k] != '\0')
		k++;
	while (k > 0)
	{
		if (i[k] == j)
			return (i + k);
		k--;
	}
	if (i[k] == j)
		return (i + k);
	return (NULL);
}
