/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:20:52 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/04 17:18:09 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_while(char *str, t_e *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int			ft_invalide_tube(char *buff, t_e **sale)
{
	t_e		*tmp;
	char	*str;
	int		i;

	tmp = *sale;
	i = 0;
	str = ft_strcdup(buff, '-');
	i += ft_while(str, tmp);
	free(str);
	tmp = *sale;
	str = ft_strdup(ft_strchr(buff, '-') + 1);
	i += ft_while(str, tmp);
	free(str);
	if (i == 2)
		return (1);
	return (0);
}
