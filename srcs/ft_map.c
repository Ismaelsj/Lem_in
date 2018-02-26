/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 09:38:22 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/14 17:13:27 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_get_ants(t_e **sale, t_p *info, int fd)
{
	char	*buff;
	int		ret;

	buff = NULL;
	while ((ret = get_next_line(fd, &buff) == 1) && buff[0] == '#'
			&& buff[1] != '#')
	{
		ft_printf("%s\n", buff);
		free(buff);
	}
	ft_printf("%s\n", buff);
	if (buff)
	{
		info->ants = ft_atol(buff);
		free(buff);
	}
	if (info->ants == 0)
		ft_error(sale, info);
}

static void		ft_initialize(t_p *info)
{
	info->sales = NULL;
	info->start = NULL;
	info->path = NULL;
	info->new_path = NULL;
	info->end = NULL;
	info->nb_sales = 0;
	info->ants = 0;
	info->invalide = 0;
}

void			ft_map(t_e **sale, t_p *info, int i)
{
	char	*buff;
	char	*prev;

	ft_get_ants(sale, info, 0);
	while (get_next_line(0, &buff) == 1
			&& ft_valide_line(buff, sale, info) == 1 && i == 0)
	{
		ft_printf("%s\n", buff);
		ft_creat(sale, info, buff, prev);
		if (ft_listlen(*sale) >= 1 && ft_invalide_sale(sale) == 0)
		{
			i = ft_del_last_list(sale);
			info->invalide = 1;
		}
		else
			info->nb_sales = ft_listlen(*sale);
		if (prev)
			free(prev);
		prev = buff;
		buff = NULL;
	}
	ft_printf("\n");
	free(prev);
	free(buff);
	ft_error(sale, info);
}

static void		ft_operat(t_e *sale, t_p *info)
{
	char	buff[5];

	if (!(info->path)
			|| ft_strcmp(ft_strrchr(info->path[0], ' ') + 1, info->end) != 0)
	{
		ft_printf("ERROR: no path found\n");
		ft_free(&sale, info);
		exit(0);
	}
	while (read(0, &buff, 4) > 0)
	{
		buff[4] = '\0';
		ft_printf("%s", buff);
		ft_bzero(buff, 4);
	}
}

int				main(int ac, char **av)
{
	t_e *sale;
	t_e *tmp;
	t_p *info;
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)ac;
	(void)av;
	info = (t_p*)malloc(sizeof(t_p));
	ft_initialize(info);
	sale = NULL;
	ft_map(&sale, info, 0);
	tmp = sale;
	while (ft_strcmp(tmp->name, info->start) != 0)
		tmp = tmp->next;
	while (ft_solve2(&sale, info, tmp, NULL))
		;
	ft_operat(sale, info);
	ft_basic_path(info);
	while (i < info->nb_sales)
	{
		j = 0;
		while (j < info->nb_sales)
		{
			ft_printf("%d ", info->sales[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
	ft_free(&sale, info);
	return (0);
}
