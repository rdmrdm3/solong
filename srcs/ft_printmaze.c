/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmaze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:05:26 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/29 22:19:23 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_printmaze(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->nbline)
	{
		j = 0;
		while (j < (*map)->nbcolumn)
		{
			printf("|%c|", (*map)->maze[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
