/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:33:45 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:11:39 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_gnl_get_save(char *save)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] != 0 && save[i] != '\n')
		i++;
	if (save[i] == 0)
	{
		kemafree(save);
		return (0);
	}
	out = kemalloc((ft_gnl_strlen(save) - i + 1), sizeof(char));
	if (!out)
		return (0);
	i++;
	while (save[i] != 0)
		out[j++] = save[i++];
	out[j] = 0;
	kemafree(save);
	return (out);
}

char	*ft_gnl_get_line(char *save)
{
	int		i;
	char	*out;

	i = 0;
	while ((save[i] != '\n') && (save[i] != 0))
		i++;
	out = kemalloc((i + 1), sizeof(char));
	if (!out)
		return (NULL);
	out[i] = 0;
	while (--i >= 0)
		out[i] = save[i];
	return (out);
}

int	ft_gnl_error_exit(char *save, char *buf)
{
	kemafree(save);
	kemafree(buf);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			head;

	head = 1;
	buf = kemalloc((BUFFER_SIZE + 1), sizeof(char));
	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0) || !buf)
		return (ft_gnl_error_exit(save, buf));
	while ((ft_gnl_new_line(save) != 0) && (head != 0))
	{
		head = read(fd, buf, BUFFER_SIZE);
		if (head < 0)
			return (ft_gnl_error_exit(save, buf));
		buf[head] = 0;
		save = ft_gnl_strjoin(save, buf);
	}
	kemafree(buf);
	*line = ft_gnl_get_line(save);
	save = ft_gnl_get_save(save);
	if (head != 0)
		return (1);
	kemafree(save);
	return (0);
}
