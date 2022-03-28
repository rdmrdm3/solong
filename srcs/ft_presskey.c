/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 14:27:42 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_presskey(int keycode, void *m)
{
	t_map *map;

	map = (t_map *) m;
	/*int y = (*map)->pspot[0][0];
   	int x = (*map)->pspot[0][1];*/
	if (map->anim == 0)
	{
	if (keycode == 53)
		printf("you just pressed escape :)\n");
	else if (keycode == 13)
	{
		map->mv = 1;
		printf("you just pressed w\n");
		/*if ((*map)->maze[(*map)->pspot[0][1] - 1][(*map)->pspot[0][0]] != '1')
			ft_pacmove(1, (*map)->pspot[0][0], (*map)->pspot[0][1], map);*/
		map->anim = 1;
	}
	else if (keycode == 0)
	{
		map->mv = 4;
		printf("you just pressed a\n");
		/*if ((*map)->maze[(*map)->pspot[0][1]][(*map)->pspot[0][0] - 1] != '1')
			ft_pacmove(4, (*map)->pspot[0][0], (*map)->pspot[0][1], map);*/
		map->anim = 1;
	}
	else if (keycode == 1)
	{
		map->mv = 3;
		printf("you just pressed s\n");
		/*if ((*map)->maze[(*map)->pspot[0][1] + 1][(*map)->pspot[0][0]] != '1')
			ft_pacmove(3, (*map)->pspot[0][0], (*map)->pspot[0][1], map);*/
		map->anim = 1;
	}
	else if (keycode == 2)
	{
		map->mv = 2;
		printf("you just pressed d\n");
		/*if ((*map)->maze[y][x + 1] != '1')
			ft_pacmove(2, (*map)->pspot[0][0], (*map)->pspot[0][1], map);*/
		map->anim = 1;
	}
	}
	//printf("you just pressed key number =>%i\n", keycode);
	return (keycode);
}
