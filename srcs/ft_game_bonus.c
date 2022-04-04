/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:37:35 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/04 20:49:15 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_game_bonus(t_map *map)
{
	int	i;

	i = 0;
	if (map->anim == 1)
	{
		map->increm++;
		if (map->increm > 25)
		{
			map->increm = 0;
			map->anim = 0;
			map->pspot[0][0] += (map->mv == 3) - (map->mv == 1);
			map->pspot[0][1] += (map->mv == 2) - (map->mv == 4);
			while (i < map->ghost)
			{
				map->gspot[i][0] += (map->gspot[i][2] == 3)
					- (map->gspot[i][2] == 1);
				map->gspot[i][1] += (map->gspot[i][2] == 2)
					- (map->gspot[i][2] == 4);
				i++;
			}
		}
		ft_pacmove(&map);
		ft_ghostmove(&map);
	}
	return (0);
}