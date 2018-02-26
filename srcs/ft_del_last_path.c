/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_last_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:55:41 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/05 11:32:09 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_del_last_path(t_p *info, t_e *sale)
{
	int		i;
	char	*tmp;
	char	*str;

	(void)sale;
	if (!(info->new_path))
		return (0);
	i = ft_strlen(info->new_path);
	while (i > -1 && info->new_path[i] != ' ')
		i--;
	tmp = info->new_path;
	str = ft_strndup(info->new_path, i);
	info->new_path = str;
	free(tmp);
	return (1);
}
