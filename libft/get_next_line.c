/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:24:50 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/16 19:38:30 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strjoin_freed(char **data, char *buf)
{
	char		*sjoin;
	size_t		i;

	i = ft_strlen(*data) + ft_strlen(buf);
	if (!(sjoin = ft_strnew(i)))
		return (NULL);
	ft_strcpy(sjoin, *data);
	ft_strcat(sjoin, buf);
	ft_strdel(data);
	return (sjoin);
}

static char			*get_line(char **data)
{
	char			*res;
	char			*tmp;
	size_t			i;

	i = 0;
	if (!(tmp = ft_strdup(*data)))
		return (NULL);
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strncpy(res, *data, i);
	ft_strdel(data);
	if (i < ft_strlen(tmp))
	{
		if (!(*data = ft_strdup(tmp + i + 1)))
			return (NULL);
	}
	else
	{
		if (!(*data = ft_strdup("\0")))
			return (NULL);
	}
	ft_strdel(&tmp);
	return (res);
}

static t_file		*find_fd(t_file **stat_lst, int fd)
{
	t_file			*tmp;

	tmp = *stat_lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (!(tmp->data = ft_strnew(0)))
		return (NULL);
	tmp->fd = fd;
	tmp->next = *stat_lst;
	*stat_lst = tmp;
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	static	t_file	*stat_lst;
	int				fdr;
	t_file			*current_lst;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(current_lst = find_fd(&stat_lst, fd)))
		return (-1);
	fdr = 0;
	while (!(ft_strchr(current_lst->data, '\n')) &&
			(fdr = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[fdr] = '\0';
		if (!(current_lst->data = ft_strjoin_freed(&current_lst->data, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!(ft_strlen(current_lst->data)))
		return (0);
	if (!(*line = get_line(&current_lst->data)))
		return (-1);
	return (1);
}
