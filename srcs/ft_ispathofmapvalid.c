/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispathofmapvalid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:17:20 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/11 15:41:39 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_ispathofmapvalid(char *arg1)
{
	int	fd;

	fd = open(arg1, O_RDONLY);
	if (!fd || fd == -1)
		return (3);
	close (fd);
	return (1);
}
