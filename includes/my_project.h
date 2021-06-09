/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_project.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/29 18:34:35 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PROJECT_H
# define MY_PROJECT_H

# include "../libs/libkema/includes/libkema.h"
# include <stdbool.h>

//	*	errors handlers

# define SUCCESS		0
# define STR_SUCCESS	"Operation success!"
# define FAILURE		-1
# define STR_FAILURE	"Operation failure!"

//	*	structs declarations

//	*	functions prototypes

//	*	main.c
int	main(int argc, char **argv, char **envp);

#endif
