/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closegame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:30:58 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 21:11:30 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_closegame(void **m)
{
	t_map **map;

	map = (t_map **)m;
//	if ((*map)->mlx == NULL)
//		printf("mlx=NULL\n");
//	mlx_destroy_window((*map)->mlx, (*map)->win);
	exit (1);
	return (0);
}
