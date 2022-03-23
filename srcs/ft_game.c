/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/23 15:50:35 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_game(t_map **map, t_vars *vars)
{
	printf("mlx = %p, win = %p\n", vars->mlx, vars->win);
//	mlx_hook(vars->win, 17, 0L, ft_closegame, vars);
	mlx_hook(vars->win, 2, 1L<<0, ft_presskey, vars);
	map = NULL;
	return (0);
}
