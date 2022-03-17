/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:32:44 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/17 16:18:09 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_printmap(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	printf("nb wall =%i\n", (*map)->wall);
	printf("nb walkway =%i\n", (*map)->walkway);
	printf("nb collectible =%i\n", (*map)->collectible);
	printf("nb player =%i\n", (*map)->player);
	printf("nb exit =%i\n", (*map)->exit);
	printf("nb ghost =%i\n", (*map)->ghost);
	printf("nb line =%i\n", (*map)->nbline);
	printf("nb column =%i\n", (*map)->nbcolumn);
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
}
