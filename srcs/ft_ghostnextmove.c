/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghostnextmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:16:53 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/04 22:55:47 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_ghostcancontinue(int i, t_square sq, t_map *map)
{
	if (map->gspot[i][2] == 1 && sq.up == 0)
		return (1);
	if (map->gspot[i][2] == 2 && sq.ri == 0)
		return (1);
	if (map->gspot[i][2] == 3 && sq.dw == 0)
		return (1);
	if (map->gspot[i][2] == 4 && sq.le == 0)
		return (1);
	return (0);
}

int	ft_ghostnextmove(t_map	*map)
{
	t_square	sq;
	int			i;

	i = -1;
	while (i < map->ghost - 1)
	{
		i++;
		sq = ft_getsquare(map->gspot[i][0], map->gspot[i][1], &map);
		if (ft_ghostcancontinue(i, sq, map) == 1)
			continue ;
		map->gspot[i][2] = 1;
		if (sq.up == 0)
			continue ;
		map->gspot[i][2] = 2;
		if (sq.ri == 0)
			continue ;
		map->gspot[i][2] = 3;
		if (sq.dw == 0)
			continue ;
		map->gspot[i][2] = 4;
		if (sq.le == 0)
			continue ;
		map->gspot[i][2] = 0;
	}
	return (0);
}
