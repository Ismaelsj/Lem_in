/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:36:02 by isidibe-          #+#    #+#             */
/*   Updated: 2018/02/10 14:22:11 by isidibe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char		*ft_display_file(const int fd)
{
	int			i;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*s1;
	char		*tmp;

	ret = 0;
	i = 0;
	if (!(s1 = (char*)malloc(sizeof(char))))
		return (NULL);
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tmp = s1;
		s1 = ft_strjoin(s1, buf);
		free(tmp);
		if ((i += ret) > 10000000)
			return (NULL);
	}
	if (ret == -1)
	{
		free(s1);
		return (NULL);
	}
	return (s1);
}

t_list		*ft_get_maillon(int fd, char **line)
{
	void	*tmpstr;
	t_list	*tmp;
	char	*str;

	if (!(str = ft_display_file(fd)))
		return (NULL);
	if (!(tmp = ft_lstnew(str, fd)))
		return (NULL);
	if (!(*line = ft_strcdup(tmp->content, '\n')))
		return (NULL);
	tmpstr = tmp->content;
	if (ft_strchr(tmp->content, '\n') == NULL)
		tmp->content += ft_strclen(tmp->content, '\0');
	else
		tmp->content += ft_strclen(tmp->content, '\n') + 1;
	if (!(tmp->content = ft_strcdup(tmp->content, '\0')))
		return (NULL);
	free(tmpstr);
	free(str);
	return (tmp);
}

int			ft_if_list(t_list **list, const int fd, char **line)
{
	t_list	*tmp;

	if (!(tmp = ft_get_maillon(fd, line)))
		return (-1);
	if (list)
	{
		tmp->next = *list;
		*list = tmp;
	}
	else
		*list = tmp;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	char			*str;

	tmp = list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
		{
			if (ft_strlen(tmp->content) == 0)
				return (0);
			if (!(*line = ft_strcdup(tmp->content, '\n')))
				return (-1);
			str = tmp->content;
			if (ft_strchr(tmp->content, '\n') == NULL)
				tmp->content += ft_strclen(tmp->content, '\0');
			else
				tmp->content += ft_strclen(tmp->content, '\n') + 1;
			tmp->content = ft_strcdup(tmp->content, '\0');
			free(str);
			return (1);
		}
		tmp = tmp->next;
	}
	return (ft_if_list(&list, fd, line));
}
