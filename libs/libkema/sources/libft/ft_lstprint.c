/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 07:07:40 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/29 11:33:56 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libkema.h"
#include <stdio.h>

void	ft_lstprint(char *format, t_list *lst)
{
	t_list				*buf;
	const unsigned char	*ptr;
	size_t				i;

	buf = lst;
	i = 0;
	while (buf)
	{
		ft_dprintf(STDOUT_FILENO, "lst[%-2d]:", i);
		if (ft_strnstr("%s", format, ft_strlen(format)) || \
			ft_strnstr("%p", format, ft_strlen(format)))
			ft_dprintf(STDOUT_FILENO, format, buf->content);
		else
		{
			ptr = buf->content;
			ft_dprintf(STDOUT_FILENO, format, *ptr);
			ft_dprintf(STDOUT_FILENO, " (%%d is converted %%255)");
		}
		ft_dprintf(STDOUT_FILENO, "\n");
		buf = buf->next;
		i++;
	}
}
