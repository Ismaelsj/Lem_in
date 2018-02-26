/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:14:31 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/14 17:11:13 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include "../Libft/includes/libft.h"
# include "../Libft/includes/get_next_line.h"
# include "../Libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_e
{
	char		*name;
	char		*x;
	char		*y;
	int			pos;
	int			path;
	struct s_e	*next;
}				t_e;

typedef struct	s_pt
{
	int			ants_nb;
	char		*name;
	struct s_pt	*next;
}				t_path;

typedef struct	s_p
{
	char		*start;
	char		*end;
	long		ants;
	int			**sales;
	char		**path;
	char		*new_path;
	int			nb_sales;
	int			invalide;
}				t_p;

long			ft_atol(const char *str);
void			ft_write(t_path *tmp, t_p *info);
void			ft_basic_path(t_p *info);
int				ft_action(t_e **sale, t_p *info, t_e **tab, int i);
char			*ft_strndup(char *str, int i);
void			ft_free_path(t_p *info);
char			*ft_strjoin_free(char *s1, char *s2);
int				ft_del_last_path(t_p *info, t_e *sale);
int				ft_is_the_same(t_p *info);
int				ft_get_path(t_p *info, t_e *sale);
int				ft_creat_path(t_p *info, t_e *sale);
void			ft_new_path(t_p *info);
int				ft_solve2(t_e **sale, t_p *info, t_e *next, t_e *prev);
int				ft_solve(t_e **sale, t_p *info, t_e *next, t_e *prev);
void			ft_room(t_e **sale, t_p *info);
void			ft_ants(t_e **sale, t_p *info);
void			ft_start(t_e **sale, t_p *info);
void			ft_end(t_e **sale, t_p *info);
void			ft_sales(t_e **sale, t_p *info);
int				ft_del_last_list(t_e **sale);
int				ft_invalide_name(t_e *tmp1, t_e *tmp2);
int				ft_invalide_sale(t_e **sale);
int				ft_invalide_sale_info(t_e **sale);
int				ft_invalide_tube(char *buff, t_e **sale);
int				ft_valide_line(char *buff, t_e **sale, t_p *info);
int				ft_listlen(t_e *sale);
void			ft_free_list(t_e **sale);
void			ft_error(t_e **sale, t_p *info);
void			ft_free(t_e **sale, t_p *info);
void			ft_init_links(t_p *info);
int				ft_newsale(t_e **sale, char *buff);
void			ft_links(t_e **sale, t_p *info, char *buff);
void			ft_creat(t_e **sale, t_p *info, char *buff, char *prev);
#endif
