/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:02:15 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/10 22:02:20 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_readmap(char *file)
{
	int	fd;
	t_map	*line1;
	t_map	*line2;
	t_map	*line3;

	fd = open("./maps/maps01.ber", O_RDONLY);
	if (!fd)
		return (ft_exitfail(1, 0));


	line1 = malloc(1 * sizeof(t_map));
	line1->line = get_next_line(fd);
	if (line1->line == NULL)
		return (NULL);
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
	return (line1);
}
