/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:46:56 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 14:58:41 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// return 11 if there not a 1 all around the map
int	ft_checkframe(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->nbcolumn - 1)
	{
		if ((*map)->maze[0][i] != '1' || (*map)->maze[(*map)->nbline - 1][i]
				!= '1')
			return (11);
		i++;
	}
	i = 1;
	while (i < (*map)->nbline - 1)
	{
		if ((*map)->maze[i][0] != '1' || (*map)->maze[i][(*map)->nbcolumn - 2]
				!= '1')
			return (11);
		i++;
	}
	return (1);
}

// check the validity of the map
int	ft_checkmap(t_map **map)
{
	if ((*map)->player != 1)
		return (7);
	if ((*map)->collectible < 1)
		return (8);
	if ((*map)->exitout != 1)
		return (9);
	if ((*map)->ghost != 0)
		return (10);
	return (ft_checkframe(map));
}
