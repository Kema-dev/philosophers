/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:01:21 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/21 14:00:27 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			pos;
	unsigned char	*little;
	unsigned char	*big;

	if (!s1 || !s2)
		return (NULL);
	big = (unsigned char *)s1;
	little = (unsigned char *)s2;
	i = 0;
	pos = 0;
	if (little[0] == 0)
		return ((char *)big);
	while ((big[i] != 0) && (pos < len))
	{
		while ((big[i] == little[i]) && (big[i] != 0) && (pos + i < len))
		{
			if (little[++i] == 0)
				return ((char *)big);
		}
		big++;
		pos++;
		i = 0;
	}
	return (NULL);
}
