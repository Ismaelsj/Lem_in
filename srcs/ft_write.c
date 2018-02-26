/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:22:51 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/09 14:36:23 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			ft_write(t_path *tmp, t_p *info)
{
	int		i;
	t_path	*path;

	i = 0;
	path = tmp;
	while (path)
	{
		if (path->ants_nb <= info->ants && path->ants_nb > 0)
		{
			if (i > 0)
				ft_printf(" ");
			ft_printf("L%d-%s", path->ants_nb, path->name);
			i++;
		}
		path = path->next;
	}
}
