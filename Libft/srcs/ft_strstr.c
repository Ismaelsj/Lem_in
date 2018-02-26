/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:40:34 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/14 16:37:32 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strcmp(to_find, "") == 0)
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && to_find[j])
				j++;
			if (!to_find[j])
				return ((char*)str + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
