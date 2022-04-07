/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:02:15 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/07 15:07:42 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// error when the map is not rectangular
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
