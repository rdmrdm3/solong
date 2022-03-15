/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:56:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/15 13:46:21 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_parsing(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		return (2);
	if (ft_ispathofmapvalid(argv[1]) != 1)
		return (3);
	if (ft_isberfile(argv[1]) != 1)
		return (4);
	if (ft_readmap(argv[1], &map) != 1)
		return (5);
	ft_checkmap(map);
	printf("out of readmap\n");
	printf("line 1 =%s\n", map->line);
	printf("line 2 =%s\n", map->next->line);
	printf("line 3 =%s\n", map->next->next->line);
	printf("line 4 =%s\n", map->next->next->next->line);
	printf("line 5 =%s\n", map->next->next->next->next->line);
	printf("line 6 =%s\n", map->next->next->next->next->next->line);
	printf("line 7 =%s\n", map->next->next->next->next->next->next->line);
	return (1);
}
