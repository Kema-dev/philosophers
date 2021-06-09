/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:35:21 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/22 14:10:13 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 64

char	*ft_gnl_get_save(char *save);
char	*ft_gnl_get_line(char *save);
int		get_next_line(int fd, char **line);
void	*ft_gnl_memset(void *s, int c, size_t n);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strcat(char *dest, const char *src, size_t i);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_gnl_new_line(char *save);

#endif