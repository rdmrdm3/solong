/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsquareghost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:02:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/05 15:03:36 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_iswallghost(char c)
{
	if (c == '1')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == 'E')
		return (3);
	return (0);
}

t_square	ft_getsquareghost(int i, int j, t_map **map)
{
	t_square	sq;

	sq.ul = ft_iswallghost((*map)->maze[i - 1][j - 1]);
	sq.up = ft_iswallghost((*map)->maze[i - 1][j]);
	sq.ur = ft_iswallghost((*map)->maze[i - 1][j + 1]);
	sq.le = ft_iswallghost((*map)->maze[i][j - 1]);
	sq.ce = ft_iswallghost((*map)->maze[i][j]);
	sq.ri = ft_iswallghost((*map)->maze[i][j + 1]);
	sq.dl = ft_iswallghost((*map)->maze[i + 1][j - 1]);
	sq.dw = ft_iswallghost((*map)->maze[i + 1][j]);
	sq.dl = ft_iswallghost((*map)->maze[i + 1][j + 1]);
	return (sq);
}
