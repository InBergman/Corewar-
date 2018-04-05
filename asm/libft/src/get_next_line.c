/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:15:12 by rdurand           #+#    #+#             */
/*   Updated: 2016/10/10 15:43:22 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		fill_line(char **line, t_buf *lst)
{
	char	*end;
	int		len;

	len = 0;
	if ((end = ft_strchr(lst->save, '\n')) != NULL)
	{
		*end = '\0';
		len = ft_strlen(end + 1);
		*line = ft_strdup(lst->save);
		if (len > 0)
			ft_memmove(lst->save, &end[1], ft_strlen(&end[1]));
		ft_bzero(lst->save + len, ft_strlen(lst->save + len));
		return (1);
	}
	*line = ft_strdup(lst->save);
	ft_strdel(&lst->save);
	return (0);
}

static t_buf	*check_fd(int fd)
{
	static t_buf	*buf = NULL;
	t_buf			*tmp;
	t_buf			*prev;

	if (!buf)
	{
		buf = ft_memalloc(sizeof(t_buf));
		buf->fd = fd;
		return (buf);
	}
	tmp = buf;
	prev = buf;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = ft_memalloc(sizeof(t_buf));
	tmp = prev->next;
	tmp->fd = fd;
	return (tmp);
}

int				get_next_line(int const fd, char **line)
{
	t_buf	*lst;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	ret = 0;
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	lst = check_fd(fd);
	if (!lst->save)
		lst->save = ft_strnew(1);
	while (!ft_strchr(lst->save, '\n'))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (fill_line(line, lst));
		buf[ret] = '\0';
		tmp = ft_strjoin(lst->save, buf);
		ft_strdel(&lst->save);
		lst->save = tmp;
	}
	return (fill_line(line, lst));
}
