/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:59:08 by isidibe-          #+#    #+#             */
/*   Updated: 2017/12/21 12:05:31 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(int spe, char *str, t_flag *tmp)
{
	char	*ptr;

	if ((ft_strcmp(str, "0") != 0 || spe == 'p'))
	{
		if ((spe == 'o' || spe == 'O')
				&& ((int)ft_strlen(str) > tmp->precision_nb
					|| tmp->precision_nb == 0))
		{
			ptr = ft_newstr(1, '0');
			str = ft_strjoin_free(ft_strdup(ptr), str);
			free(ptr);
		}
		else if (((spe == 'x' || spe == 'X')
				&& tmp->precision_nb != 0) || spe == 'p')
		{
			if ((tmp->precision_nb == 0 || tmp->precision_st == 0)
				&& spe == 'p')
				str = ft_strjoin_free(ft_newstr(1, '0'), str);
			else
				str = ft_strjoin_free(ft_newstr(2, '0'), str);
			str[1] = 'x';
		}
	}
	return (str);
}
