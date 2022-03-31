/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 17:44:35 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// print the number of move in the shell
int	ft_printmove(t_map *map)
{
	map->nbmove++;
	write(1, "Pacman moved ", 13);
	ft_putnbmove(map->nbmove);
	if (map->nbmove <= 1)
		write(1, " time.\n", 7);
	else
		write(1, " times.\n", 8);
	return (0);
}

// a or b equal to -1 or +1 depending on the direction
// up a=-1, down a=1, right b=1, left b=-1
int	ft_ifmove(t_map *map, int m, int a, int b)
{
	if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == '0')
	{
		map->mv = m;
		map->anim = 1;
		ft_printmove(map);
	}
	else if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == 'C')
	{
		map->mv = m;
		map->anim = 1;
		ft_printmove(map);
		map->collectible--;
		map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] = '0';
		if (map->collectible == 0)
			ft_changedoor(map);
	}
	else if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == 'E')
	{
		if (map->collectible == 0)
			exit(1);
	}
	return (0);
}

// keycode=53 => escape
// keycode=13 => w or up
// keycode=0  => a or left
// keycode=1  => s or down
// keycode=2  => d or right
int	ft_presskey(int keycode, void *m)
{
	t_map	*map;

	map = (t_map *)m;
	if (map->anim == 0)
	{
		if (keycode == 53)
			exit(1);
		else if (keycode == 13 || keycode == 126)
			ft_ifmove(map, 1, -1, 0);
		else if (keycode == 0 || keycode == 123)
			ft_ifmove(map, 4, 0, -1);
		else if (keycode == 1 || keycode == 125)
			ft_ifmove(map, 3, 1, 0);
		else if (keycode == 2 || keycode == 124)
			ft_ifmove(map, 2, 0, 1);
	}
	return (0);
}

/*
int	ft_presskey(int keycode, void *m)
{
	t_map	*map;

	map = (t_map *)m;
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
				map->maze[map->pspot[0][0] - 1][map->pspot[0][1]] = '0';
				if (map->collectible == 0)
					ft_changedoor(map);
			}
			else if (map->maze[map->pspot[0][0] - 1][map->pspot[0][1]] == 'E')
			{
				if (map->collectible == 0)
					exit(1);
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
				map->maze[map->pspot[0][0]][map->pspot[0][1] - 1] = '0';
				if (map->collectible == 0)
					ft_changedoor(map);
			}
			else if (map->maze[map->pspot[0][0]][map->pspot[0][1] - 1] == 'E')
			{
				if (map->collectible == 0)
					exit(1);
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
				map->maze[map->pspot[0][0] + 1][map->pspot[0][1]] = '0';
				if (map->collectible == 0)
					ft_changedoor(map);
			}
			else if (map->maze[map->pspot[0][0] + 1][map->pspot[0][1]] == 'E')
			{
				if (map->collectible == 0)
					exit(1);
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
				map->maze[map->pspot[0][0]][map->pspot[0][1] + 1] = '0';
				if (map->collectible == 0)
					ft_changedoor(map);
			}
			else if (map->maze[map->pspot[0][0]][map->pspot[0][1] + 1] == 'E')
			{
				if (map->collectible == 0)
					exit(1);
			}
		}
	}
	return (0);
}
*/
