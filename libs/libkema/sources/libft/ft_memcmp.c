/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:58:25 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/05 15:42:01 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	if (!s1 || !s2 || (n == 0))
		return (0);
	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (src1[i] == src2[i] && i < n - 1)
		i++;
	return ((unsigned int)src1[i] - (unsigned int)src2[i]);
}
