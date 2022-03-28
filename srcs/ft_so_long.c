/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:38:30 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 14:25:45 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	main(int argc, char **argv)
{
	int		parsingresult;
	t_map	m;
	t_map	*map;

	map = &m;
	parsingresult = ft_parsing(argc, argv, &map);
	if (parsingresult != 1)
		return (ft_exitfail(1, parsingresult));
	ft_displaymap(&map);
	map->frame= 0;
	map->anim = 0;
	map->mv = 0;
	mlx_hook(map->win, 17, 0L, ft_closegame, map);
	mlx_key_hook(map->win, ft_presskey, map);
	mlx_loop_hook(map->mlx, ft_game, map);
	mlx_loop(map->mlx);
	return (0);
}
