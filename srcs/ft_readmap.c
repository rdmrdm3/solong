/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:02:15 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:28 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_countwall(char c, t_map **map)
{
	if (c == '0')
		(*map)->walkway++;
	else if (c == '1')
		(*map)->wall++;
	else if (c == 'C')
		(*map)->collectible++;
	else if (c == 'E')
		(*map)->exit++;
	else if (c == 'P')
		(*map)->player++;
	else if (c == 'G')
		(*map)->ghost++;
	else
		return (-1);
	return (1);
}

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
	{
		free(line);
		return (6);
	}
	free(line);
	close (fd);
	ft_inputmap(arg1, map);
	return (1);
}
