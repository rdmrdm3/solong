/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closegame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:30:58 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/21 16:42:18 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_closegame(t_vars *vars)
{
	printf("mlx = %p, win = %p\n", vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	write(1, "2\n", 2);
	return (0);
}
