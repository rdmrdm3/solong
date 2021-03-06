/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:38:30 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/07 14:32:13 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

//	map = malloc (1 * sizeof(t_map));
//	mlx_hook(map->win, 2, 1L<<0, ft_presskey, map);
int	main(int argc, char **argv)
{
	int		parsingresult;
	t_map	*map;
	t_map	m;

	map = &m;
	parsingresult = ft_parsing(argc, argv, &map);
	if (parsingresult != 1)
		return (ft_exitfail(1, parsingresult));
	ft_displaymap(&map);
	mlx_hook(map->win, 17, 0L, ft_closegame, map);
	mlx_key_hook(map->win, ft_presskey, map);
	mlx_loop_hook(map->mlx, ft_game, map);
	mlx_loop(map->mlx);
	return (1);
}
