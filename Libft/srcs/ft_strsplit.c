/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:00:43 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/26 10:27:35 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wordsnbr(char const *s, char c)
{
	size_t	i;
	int		j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

static int	ft_taille(char const *s, char c, int i)
{
	size_t	j;

	j = 1;
	while (s[i] && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

static char	*ft_dup(char const *s, char c, int i)
{
	char	*dup;
	int		j;

	j = 0;
	dup = (char*)malloc(sizeof(char*) * (ft_taille(s, c, i) + 1));
	if (!dup)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		dup[j] = s[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char**)malloc(sizeof(char**) * (ft_wordsnbr(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[j] = ft_dup(s, c, i);
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	str[j] = 0;
	return (str);
}
