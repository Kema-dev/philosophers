/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:58:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/11 11:36:35 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n-- > 0)
		d[n] = s[n];
	return (dest);
}
