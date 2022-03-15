/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:02:15 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/14 21:06:03 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_readmap(char *arg1, t_map **map)
{
	int		fd;
	t_map	*line1;
	t_map	*line2;
	t_map	*line3;

	fd = open(arg1, O_RDONLY);
	if (!fd)
		return (5);
	line1 = malloc(1 * sizeof(t_map));
	line1->line = get_next_line(fd);
	if (line1->line == NULL)
		return (0);
	line1->next = NULL;
	line2 = line1;
	while (line2->line != NULL)
	{
		line3 = malloc(1 * sizeof(t_map));
		line3->line = get_next_line(fd);
		line3->next = NULL;
		line2->next = line3;
		line2 = line3;
	}
	*map = line1;
	return (1);
}
