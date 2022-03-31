/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispathofmapvalid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:17:20 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 12:08:55 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// check if the map cam be open at the given path
int	ft_ispathofmapvalid(char *arg1)
{
	int	fd;

	fd = open(arg1, O_RDONLY);
	if (!fd || fd == -1)
		return (3);
	close (fd);
	return (1);
}
