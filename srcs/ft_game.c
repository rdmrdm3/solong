/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/29 20:38:39 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_game(t_map *map)
{
//	printf("mlx = %p, win = %p\n", map->mlx, map->win);
//	printf("game increm=%i\n", map->increm);
	
	if (map->anim == 1)
	{
		map->increm++;
		if (map->increm > 25)
		{
			map->increm = 0;
			map->anim = 0;
			map->pspot[0][0] += (map->mv == 3) - (map->mv == 1);
			map->pspot[0][1] += (map->mv == 2) - (map->mv == 4);
		}
		ft_pacmove(map->mv, map->pspot[0][0], map->pspot[0][1], &map);
	}
	return (0);
}
