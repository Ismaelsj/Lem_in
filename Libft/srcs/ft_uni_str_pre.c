/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_str_pre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:12:58 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 14:59:19 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_byte_nb(int i)
{
	if ((i >= 0xd800 && i <= 0xdfff) || i < 0)
		return (0);
	if (i <= 255)
		return (1);
	else if (i <= 0x7FF)
		return (2);
	else if (i <= 0xFFFF)
		return (3);
	else if (i <= 0x10FFFF)
		return (4);
	return (0);
}

char			*ft_uni_str_pre(wchar_t *str, t_flag *tmp, int nb)
{
	char	*s;
	char	*tp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s = (char*)malloc(sizeof(char))))
		return (NULL);
	while (str[i])
	{
		j += ft_byte_nb(str[i]);
		if ((tp = ft_uni(str[i], tmp)) == NULL && j > nb)
			return (s);
		else if ((s = ft_strjoin_free(s, tp)) == NULL)
			return (NULL);
		i++;
	}
	return (s);
}

char			*ft_uni_str(wchar_t *str, t_flag *tmp)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char))))
		return (NULL);
	while (str != NULL && str[i])
	{
		if ((s = ft_strjoin_free(s, ft_uni(str[i], tmp))) == NULL)
			return (NULL);
		i++;
	}
	return (s);
}
