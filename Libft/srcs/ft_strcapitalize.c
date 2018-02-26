/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:54:47 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/10 13:42:49 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_islower(str[i]) == 1 && ft_isalnum(str[i - 1]) == 0)
			str[i] -= 32;
		else if (ft_isupper(str[i]) == 1 && ft_isalpha(str[i - 1]) == 1)
			str[i] += 32;
		i++;
	}
	return (str);
}
