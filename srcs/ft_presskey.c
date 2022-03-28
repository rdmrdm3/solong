/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 23:06:40 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_presskey(int keycode, t_map **map)
{
//	t_map	**map;
//	map = (t_map **)m;
//	int y = (*map)->pspot[0][0];
//   	int x = (*map)->pspot[0][1];
//	printf("press increm=%i\n", (*map)->increm);
//	(*map)->key = keycode;
//	printf("y=%d	x=%d\n", y, x);
//	printf("(y, x+1)=>%c\n", (*map)->maze[y][x + 1]);	
//	printf("(y, x-1)=>%c\n", (*map)->maze[y][x - 1]);	
//	printf("(y+1, x)=>%c\n", (*map)->maze[y + 1][x]);	
//	printf("(y-1, x+1)=>%c\n", (*map)->maze[y - 1][x]);	
	printf("anim =%i\n", (*map)->anim);
	if ((*map)->anim == 0)
	{
		if (keycode == 53)
			printf("you just pressed escape :)\n");
		else if (keycode == 13)
		{
			printf("you just pressed w\n");
			(*map)->mv = 1;
			(*map)->anim = 1;
//			if ((*map)->maze[(*map)->pspot[0][1] - 1][(*map)->pspot[0][0]] != '1')
//				ft_pacmove(1, (*map)->pspot[0][0], (*map)->pspot[0][1], map);
		}
		else if (keycode == 0)
		{
			printf("you just pressed a\n");
			(*map)->mv = 4;
			(*map)->anim = 1;
//			if ((*map)->maze[(*map)->pspot[0][1]][(*map)->pspot[0][0] - 1] != '1')
//				ft_pacmove(4, (*map)->pspot[0][0], (*map)->pspot[0][1], map);
		}
		else if (keycode == 1)
		{
			printf("you just pressed s\n");
			(*map)->mv = 3;
			(*map)->anim = 1;
//			if ((*map)->maze[(*map)->pspot[0][1] + 1][(*map)->pspot[0][0]] != '1')
//				ft_pacmove(3, (*map)->pspot[0][0], (*map)->pspot[0][1], map);
		}
		else if (keycode == 2)
		{
			printf("you just pressed d\n");
			(*map)->mv = 2;
			(*map)->anim = 1;
//		if ((*map)->maze[y][x + 1] != '1')
//		{
//			ft_pacmove(2, (*map)->pspot[0][0], (*map)->pspot[0][1], map);
//			printf("Pac just went right :)\n");
//		}
//		else
//			printf("mur\n");
		}
	}
	//printf("you just pressed key number =>%i\n", keycode);
	return (keycode);
}
