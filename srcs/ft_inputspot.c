/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputspot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:45:50 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 14:46:41 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// input the coordinate of the player
void	ft_inputpspot(t_map **map, int i, int j)
{
	(*map)->pspot[0][0] = i;
	(*map)->pspot[0][1] = j;
	return ;
}

// input the coordinate of the exit
void	ft_inputespot(t_map **map, int i, int j)
{
	(*map)->espot[0][0] = i;
	(*map)->espot[0][1] = j;
	return ;
}

// input the coordinate of the ghost number ng
int	ft_inputgspot(t_map **map, int ng, int i, int j)
{
	(*map)->gspot[ng][0] = i;
	(*map)->gspot[ng][1] = j;
	(*map)->gspot[ng][2] = 0;
	ng++;
	return (ng);
}

// input the coordinates of the player, exit and ghosts. 
int	ft_inputspotval(t_map **map)
{
	int	i;
	int	j;
	int	ng;

	ng = 0;
	i = 0;
	while (i < (*map)->nbline)
	{
		j = 0;
		while (j < (*map)->nbcolumn - 1)
		{
			if ((*map)->maze[i][j] == 'P')
				ft_inputpspot(map, i, j);
			if ((*map)->maze[i][j] == 'E')
				ft_inputespot(map, i, j);
			if ((*map)->maze[i][j] == 'G')
				ng = ft_inputgspot(map, ng, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

/*
// 
int	ft_inputspotval(t_map **map)
{
	int	i;
	int	j;
	int	ne;
	int	nc;
	int	ng;

	ne = 0;
	nc = 0;
	ng = 0;
	i = 0;
	while (i < (*map)->nbline)
	{
		j = 0;
		while (j < (*map)->nbcolumn - 1)
		{
			if ((*map)->maze[i][j] == 'P')
			{
				(*map)->pspot[0][0] = i;
				(*map)->pspot[0][1] = j;
			}
			if ((*map)->maze[i][j] == 'C')
			{
				(*map)->cspot[nc][0] = i;
				(*map)->cspot[nc][1] = j;
				nc++;
			}
			if ((*map)->maze[i][j] == 'E')
			{
				(*map)->espot[ne][0] = i;
				(*map)->espot[ne][1] = j;
				ne++;
			}
			if ((*map)->maze[i][j] == 'G')
			{
				(*map)->gspot[ng][0] = i;
				(*map)->gspot[ng][1] = j;
				(*map)->gspot[ng][2] = 0;
				ng++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
*/

// create the structure that contains the coordinates of the player, exit ...
int	ft_inputspot(t_map **map)
{
	int	i;

	(*map)->gspot = malloc ((*map)->ghost * sizeof(int *));
	(*map)->espot = malloc ((*map)->exitout * sizeof(int *));
	(*map)->cspot = malloc ((*map)->collectible * sizeof(int *));
	(*map)->pspot = malloc (1 * sizeof(int *));
	(*map)->pspot[0] = malloc (2 * sizeof(int *));
	i = 0;
	while (i < (*map)->ghost)
		(*map)->gspot[i++] = malloc (3 * sizeof(int *));
	i = 0;
	while (i < (*map)->exitout)
		(*map)->espot[i++] = malloc (2 * sizeof(int *));
	i = 0;
	while (i < (*map)->collectible)
		(*map)->cspot[i++] = malloc (2 * sizeof(int *));
	ft_inputspotval(map);
	return (0);
}
