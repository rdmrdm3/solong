/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:38:30 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/23 19:41:53 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	main(int argc, char **argv)
{
	int		parsingresult;
	t_map	*map;

	map = malloc (1 * sizeof(t_map));
	parsingresult = ft_parsing(argc, argv, &map);
	if (parsingresult != 1)
		return (ft_exitfail(1, parsingresult));
	ft_displaymap(&map);
	ft_game(&map);
	mlx_loop(map->mlx);
	return (0);
}
