/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:48:05 by isidibe-          #+#    #+#             */
/*   Updated: 2018/01/29 11:50:17 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_room(t_e **sale, t_p *info)
{
	ft_printf("ERROR: invalid room\n");
	ft_free(sale, info);
}

void	ft_ants(t_e **sale, t_p *info)
{
	ft_printf("ERROR: invalid number of ants\n");
	ft_free(sale, info);
}

void	ft_start(t_e **sale, t_p *info)
{
	ft_printf("ERROR: invalid start\n");
	ft_free(sale, info);
}

void	ft_end(t_e **sale, t_p *info)
{
	ft_printf("ERROR: invalid end\n");
	ft_free(sale, info);
}

void	ft_sales(t_e **sale, t_p *info)
{
	ft_printf("ERROR: no path founded\n");
	ft_free(sale, info);
}
