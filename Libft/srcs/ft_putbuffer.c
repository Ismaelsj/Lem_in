/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsMac <isidibe-@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:07:47 by IsMac             #+#    #+#             */
/*   Updated: 2018/02/21 10:58:11 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_plusplus(t_flag *tmp)
{
	tmp->index++;
	tmp->bites_nb++;
}

int				ft_putbuffer(char *str, char *buff, t_flag *tmp)
{
	int i;

	i = 0;
	if (str == NULL)
		return (-1);
	if (tmp->bzero == 1 && tmp->minus == '-')
		ft_plusplus(tmp);
	while (str[i])
	{
		if (tmp->index == TAILLE_MAX_BUFF - 1)
		{
			write(tmp->fd, buff, tmp->index);
			ft_bzero(buff, tmp->index);
			tmp->index = 0;
		}
		buff[tmp->index] = str[i];
		ft_plusplus(tmp);
		i++;
	}
	if (tmp->bzero == 1 && tmp->minus == -1)
		ft_plusplus(tmp);
	if (str)
		free(str);
	return (0);
}
