/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:38:46 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/07 15:11:48 by rdi-marz         ###   ########.fr       */
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
		(*map)->errchar = 1;
	return (1);
}

// 
char	**ft_inputmapcore(char **inmaze, t_map **map, char *line, int i)
{
	int		j;

	j = 0;
	while (j < (*map)->nbcolumn - 1)
	{
		inmaze[i][j] = line[j];
		ft_countwall(inmaze[i][j], map);
		j++;
	}
	inmaze[i][j] = '\0';
	return (inmaze);
}

// create the map in the char **
int	ft_inputmap(char *arg1, t_map **map)
{
	char	*line;
	char	**inmaze;
	int		i;
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
		inmaze = ft_inputmapcore(inmaze, map, line, i);
		free(line);
		i++;
	}
	(*map)->maze = inmaze;
	close (fd);
	return (1);
}
