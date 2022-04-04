/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:43:12 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/02 23:43:53 by rdi-marz         ###   ########.fr       */
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
	parsingresult = ft_parsing_bonus(argc, argv, &map);
	if (parsingresult != 1)
		return (ft_exitfail_bonus(1, parsingresult));
	ft_displaymap(&map);
	mlx_hook(map->win, 17, 0L, ft_closegame, map);
	mlx_key_hook(map->win, ft_presskey_bonus, map);
	mlx_loop_hook(map->mlx, ft_game_bonus, map);
	mlx_loop(map->mlx);
	return (0);
}
