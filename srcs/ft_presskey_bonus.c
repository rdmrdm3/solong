/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:03:06 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/05 12:55:24 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// print the number of move in the shell
void	ft_printmove_bonus(t_map *map)
{
	char	*txt;

	map->nbmove++;
	txt = ft_itoa(map->nbmove);
	mlx_string_put(map->mlx, map->win, 0, 10, 0xFFFFFFFF, "Number of move :");
	mlx_string_put(map->mlx, map->win, 115, 10, 0x00FFFFFF, txt);
	free(txt);
}

// congrats, you won !
// too bad, you lost !
void	ft_winorlose_bonus(t_map *map, int i)
{
	ft_printmove_bonus(map);
	if (i == 1)
		write(1, "Congratulations, you won !\n", 27);
	else
		write(1, "Too bad, you lost :(!\n", 22);
	exit (1);
}

// a or b equal to -1 or +1 depending on the direction
// up a=-1, down a=1, right b=1, left b=-1
int	ft_ifmove_bonus(t_map *map, int m, int a, int b)
{
	if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == '0')
	{
		map->mv = m;
		map->anim = 1;
		ft_printmove_bonus(map);
	}
	else if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == 'C')
	{
		map->mv = m;
		map->anim = 1;
		ft_printmove_bonus(map);
		map->collectible--;
		map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] = '0';
		if (map->collectible == 0)
			ft_changedoor(map);
	}
	else if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == 'E')
	{
		if (map->collectible == 0)
			ft_winorlose_bonus(map, 1);
	}
	else if (map->maze[map->pspot[0][0] + a][map->pspot[0][1] + b] == 'G')
		ft_winorlose_bonus(map, 0);
	return (0);
}

// keycode=53 => escape
// keycode=13 => w or up
// keycode=0  => a or left
// keycode=1  => s or down
// keycode=2  => d or right
int	ft_presskey_bonus(int keycode, void *m)
{
	t_map	*map;

	map = (t_map *)m;
	if (map->anim == 0)
	{
		ft_ghostnextmove(map);
		if (keycode == 53)
			exit(1);
		else if (keycode == 13 || keycode == 126)
			ft_ifmove_bonus(map, 1, -1, 0);
		else if (keycode == 0 || keycode == 123)
			ft_ifmove_bonus(map, 4, 0, -1);
		else if (keycode == 1 || keycode == 125)
			ft_ifmove_bonus(map, 3, 1, 0);
		else if (keycode == 2 || keycode == 124)
			ft_ifmove_bonus(map, 2, 0, 1);
	}
	return (0);
}
