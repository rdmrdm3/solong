/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:27:53 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/30 21:41:14 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_freemap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nbline)
	{
		free(map->maze[i]);
		i++;
	}
	free (map->maze);
	free (map->gspot);
	free (map->espot);
	free (map->cspot);
	free (map->pspot);
	return (0);
}
