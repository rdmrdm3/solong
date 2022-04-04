/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghostfirstmove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:22:06 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/04 17:17:14 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_ghostfirstmove(t_map	*map)
{
	t_square	sq;
	int			i;

	i = 0;
//	sq = NULL;
	while (i < map->ghost)
	{
		sq = ft_getsquare(map->gspot[i][1], map->gspot[i][0], &map);
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
		i++;
	}
	return (0);
}
