/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:41:47 by isidibe-          #+#    #+#             */
/*   Updated: 2017/11/11 13:36:12 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_endstr(char const *s)
{
	size_t j;

	j = ft_strlen(s);
	while ((s[j] == ' ' || s[j] == '\n'
				|| s[j] == '\t' || s[j] == '\0') && j > 0)
		j--;
	return (j);
}

static size_t		ft_startstr(char const *s)
{
	size_t i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	k = 0;
	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(str))
		return (NULL);
	j = ft_endstr(s);
	i = ft_startstr(s);
	if (s[i] == '\0')
	{
		str[0] = '\0';
		return (str);
	}
	if (j <= i)
		return (str);
	while (i < j)
		str[k++] = s[i++];
	str[k++] = s[i];
	str[k] = '\0';
	return (str);
}
