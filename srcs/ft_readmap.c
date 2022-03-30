/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:02:15 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/30 21:03:48 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// count how many of each type are in the map
int	ft_countwall(char c, t_map **map)
{
	if (c == '0')
		(*map)->walkway++;
	else if (c == '1')
		(*map)->wall++;
	else if (c == 'C')
		(*map)->collectible++;
	else if (c == 'E')
		(*map)->exitout++;
	else if (c == 'P')
		(*map)->player++;
	else if (c == 'G')
		(*map)->ghost++;
	else
		return (-1);
	return (1);
}

// create the map in the char **
int	ft_inputmap(char *arg1, t_map **map)
{
	char	*line;
	char	**inmaze;
	int		i;
	int		j;
	int		fd;

	fd = open(arg1, O_RDONLY);
	if (!fd)
		return (5);
	inmaze = malloc ((*map)->nbline * sizeof(char *));
	i = 0;
	while (i < (*map)->nbline)
	{
		line = get_next_line(fd);
		inmaze[i] = malloc ((*map)->nbcolumn * sizeof (char *));
		j = 0;
		while (j < (*map)->nbcolumn - 1)
		{
			inmaze[i][j] = line[j];
			ft_countwall(inmaze[i][j], map);
			j++;
		}
		inmaze[i][j] = '\0';
		i++;
	}
	(*map)->maze = inmaze;
	close (fd);
	return (1);
}

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

int	ft_error6(char *line)
{
	free(line);
	return (6);
}

int	ft_readmap(char *arg1, t_map **map)
{
	int		fd;
	char	*line;

	fd = open(arg1, O_RDONLY);
	if (!fd)
		return (5);
	(*map)->nbline = 1;
	line = get_next_line(fd);
	(*map)->nbcolumn = ft_strlen(line);
	while ((*map)->nbcolumn == ft_strlen(line))
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(*map)->nbline++;
	}	
	if (line != NULL)
		return (ft_error6(line));
	free(line);
	close (fd);
	ft_inputmap(arg1, map);
	ft_inputspot(map);
	return (1);
}
