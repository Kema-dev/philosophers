/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:58:20 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/05 15:41:57 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	if (!s)
		return (NULL);
	i = -1;
	src = (unsigned char *)s;
	while (++i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)(s + i));
	}
	return (NULL);
}
