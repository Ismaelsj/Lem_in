/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:33:57 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/11 15:37:53 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]) == 1)
			str[i] += 32;
		i++;
	}
	return (str);
}
