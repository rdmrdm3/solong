/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/30 10:23:50 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_presskey(int keycode, void *m)
{
	t_map	*map;
	map = (t_map *) m;
//	printf("anim =%i\n", (*map)->anim);
	if (map->anim == 0)
	{
		if (keycode == 53)
		{
			printf("you just pressed escape :)\n");
			exit(1);
		}
		else if (keycode == 13 || keycode == 126)
		{
			printf("you just pressed w\n");
			if (map->maze[map->pspot[0][0] - 1][map->pspot[0][1]] == '0')
			{
				map->mv = 1;
				map->anim = 1;
				map->nbmove++;
			}
			else if (map->maze[map->pspot[0][0] - 1][map->pspot[0][1]] == 'C')
			{
				map->mv = 1;
				map->anim = 1;
				map->nbmove++;
				map->collectible--;
				if (map->collectible == 0)
					ft_changedoor(map);
			}
		}
		else if (keycode == 0 || keycode == 123)
		{
			printf("you just pressed a\n");
			if (map->maze[map->pspot[0][0]][map->pspot[0][1] - 1] == '0')
			{
				map->mv = 4;
				map->anim = 1;
				map->nbmove++;
			}
			else if (map->maze[map->pspot[0][0]][map->pspot[0][1] - 1] == 'C')
			{
				map->mv = 4;
				map->anim = 1;
				map->nbmove++;
				map->collectible--;
				if (map->collectible == 0)
					ft_changedoor(map);
			}
		}
		else if (keycode == 1 || keycode == 125)
		{
			printf("you just pressed s\n");
			if (map->maze[map->pspot[0][0] + 1][map->pspot[0][1]] == '0')
			{	
				map->mv = 3;
				map->anim = 1;
				map->nbmove++;
			}
			else if (map->maze[map->pspot[0][0] + 1][map->pspot[0][1]] == 'C')
			{
				map->mv = 3;
				map->anim = 1;
				map->nbmove++;
				map->collectible--;
				if (map->collectible == 0)
					ft_changedoor(map);
			}

		}
		else if (keycode == 2 || keycode == 124)
		{
			printf("you just pressed d\n");
			if (map->maze[map->pspot[0][0]][map->pspot[0][1] + 1] == '0')
			{
				map->mv = 2;
				map->anim = 1;
				map->nbmove++;
			}
			else if (map->maze[map->pspot[0][0]][map->pspot[0][1] + 1] == 'C')
			{
				map->mv = 2;
				map->anim = 1;
				map->nbmove++;
				map->collectible--;
				if (map->collectible == 0)
					ft_changedoor(map);
			}

		}
	}
//	printf("you just pressed key number =>%i\n", keycode);
	return (keycode);

