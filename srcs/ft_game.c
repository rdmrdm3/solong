/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 08:34:24 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_game(t_map **map)
{
	static int	t;
	int			key;

	t = 0;
	key = -1;
	printf("mlx = %p, win = %p\n", (*map)->mlx, (*map)->win);
	mlx_hook((*map)->win, 17, 0L, ft_closegame, map);
	if (t == 0)
	{
		mlx_hook((*map)->win, 2, 1L<<0, key = ft_presskey, map);
		t++;
	}
	else
	{
		ft_presskey(key, map);
		t++;
		if (t == 24)
		{
			t = 0;
			key = -1;
		}
	}
	map = NULL;
	return (0);
}
