/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closegame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:30:58 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/25 15:47:47 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_closegame(t_map **map)
{
	printf("mlx = %p, win = %p\n", (*map)->mlx, (*map)->win);
//	mlx_destroy_window((*map)->mlx, (*map)->win);
//	write(1, "2\n", 2);
	exit (1);
	return (0);
}
