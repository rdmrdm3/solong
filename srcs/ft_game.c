/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/23 20:12:20 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_game(t_map **map)
{
	printf("mlx = %p, win = %p\n", (*map)->mlx, (*map)->win);
//	mlx_hook((*map)->win, 17, 0L, ft_closegame, map);
	mlx_hook((*map)->win, 2, 1L<<0, ft_presskey, map);
	map = NULL;
	return (0);
}
