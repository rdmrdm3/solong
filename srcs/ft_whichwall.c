/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichwall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:25:02 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/18 09:33:56 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_so_long.h>

int	ft_iswall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

t_square	ft_getsqure(int i, int j, t_map **map)
{
	t_square	sq;

	sq.ul = ft_iswall((*map)->maze[i - 1][j - 1]);
	sq.up = ft_iswall((*map)->maze[i - 1][j]);
	sq.ur = ft_iswall((*map)->maze[i - 1][j + 1]);
	sq.le = ft_iswall((*map)->maze[i][j - 1]);
	sq.ce = ft_iswall((*map)->maze[i][j]);
	sq.ri = ft_iswall((*map)->maze[i][j + 1]);
	sq.dl = ft_iswall((*map)->maze[i + 1][j - 1]);
	sq.dw = ft_iswall((*map)->maze[i + 1][j]);
	sq.dl = ft_iswall((*map)->maze[i + 1][j + 1]);
	return (sq);
}

char	*ft_frame(int i, int j, t_map **map)
{
	if (i == 0 && j == 0)
		return ("./image/wall04.xpm");
	if (i == 0 && j == (*map)->nbcolumn - 1)
		return ("./image/wall05.xpm");
	if (i == (*map)->nbline && j == (*map)->nbcolumn -1)
		return ("./image/wall06.xpm");
	if (i == (*map)->nbline && j == 0)
		return ("./image/wall03.xpm");
	if (i == 0 && (*map)->maze[1][j] != '1')
		return ("./image/wall02.xpm");
	if (i == 0 && (*map)->maze[1][j] == '1')
		return ("./image/wall08.xpm");
	if (i == (*map)->nbline && (*map)->maze[(*map)->nbline - 1][j] != '1')
		return ("./image/wall02.xpm");
	if (i == (*map)->nbline && (*map)->maze[(*map)->nbline - 1][j] == '1')
		return ("./image/wall10.xpm");
	if (j == 0 && (*map)->maze[i][1] != '1')
		return ("./image/wall01.xpm");
	if (j == 0 && (*map)->maze[i][1] == '1')
		return ("./image/wall07.xpm");
	if (j == (*map)->nbcolumn && (*map)->maze[i][(*map)->nbcolumn - 1] != '1')
		return ("./image/wall01.xpm");
	if (j == (*map)->nbcolumn && (*map)->maze[i][(*map)->nbcolumn - 1] == '1')
		return ("./image/wall09.xpm");
}

char	*ft_whichwall(int i, int j, t_map **map)
{
	t_square	sq;

	if (i == 0 || i == (*map)->nbline || j == 0 || j == (*map)->nbcolumn - 1)
		return (ft_frame(i, j, map));
	sq = ft_getsquare(i, j, map);
	if (sq.up + sq.le + sq.ri + sq.dw == 1)
		// 1 wall	
	if (sq.up + sq.le + sq.ri + sq.dw == 2)
		// 2 walls
	if (sq.up + sq.le + sq.ri + sq.dw == 3)
		// 3 walls
	if (sq.up + sq.le + sq.ri + sq.dw == 4)
		// 4 walls
	return ("./image/wall16.xpm");
}







