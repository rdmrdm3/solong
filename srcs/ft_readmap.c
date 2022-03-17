/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:02:15 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/16 21:03:13 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_inputmap(char *arg1, int nbl, int nbc, char ***map)
{
	char	*line;
	char	**inmap;
	int		i;
	int		j;
	int		fd;

	fd = open(arg1, O_RDONLY);
	if (!fd)
		return (5);
	inmap = malloc (nbl * sizeof(char *));
	i = 0;
	while (i < nbl - 1)
	{
		line = get_next_line(fd);
		inmap[i] = malloc (nbc * sizeof (char *));
		j = 0;
		while (j < nbc - 2)
		{
			inmap[i][j] = line[j];
			j++;
		}
		i++;
	}
	*map = inmap;
	close (fd);
	return (1);
}

int	ft_readmap(char *arg1, t_map **map)
{
	int		fd;
	int		nbline;
	int		nbcolumn;
	char	*line;

	fd = open(arg1, O_RDONLY);
	if (!fd)
		return (5);
	nbline = 1;
	line = get_next_line(fd);
	nbcolumn = ft_strlen(line);
	while (nbcolumn == ft_strlen(line))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nbline++;
	}	
	if (line != NULL)
		return (6);
	close (fd);
	ft_inputmap(arg1, nbline, nbcolumn, map);
	return (1);
}
