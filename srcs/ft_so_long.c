/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:38:30 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 17:54:35 by rdi-marz         ###   ########.fr       */
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
	printf("anim=%i, mv=%i\n", map->anim, map->mv);
	printf("after displaymap\n");
	mlx_hook(map->win, 17, 0L, ft_closegame, map);
	mlx_hook(map->win, 2, 1L<<0, ft_presskey, map);
//		mlx_key_hook((*map)->win, ft_presskey, map);
	mlx_loop_hook(map->win, ft_presskey, map);
	printf("after ft_game\n");
	mlx_loop(map->mlx);
	return (0);
}

/*
int	mainold(int argc, char **argv)
{
	int		parsingresult;
	t_map	*map;

	map = malloc (1 * sizeof(t_map));
	parsingresult = ft_parsing(argc, argv, &map);
	if (parsingresult != 1)
		return (ft_exitfail(1, parsingresult));
//	printf("after parsing\n");
	ft_displaymap(&map);
	printf("after displaymap\n");
	mlx_hook((*map).win, 17, 0L, ft_closegame, map);
	if ((*map).increm == 0)
	{
		mlx_hook((*map).win, 2, 1L<<0, ft_presskey, map);
//		mlx_key_hook((*map)->win, ft_presskey, map);
		(*map).increm++;
	}
	else
	{
//		ft_presskey((*map).key, &map);
		(*map).increm++;
		if ((*map).increm == 24)
		{
			(*map).increm = 0;
			(*map).key = -1;
		}
	}
	printf("increm=%i\n", (*map).increm);
//	mlx_hook((*map).win, 2, 1L<<0, ft_presskey, map);
	mlx_loop_hook((*map).win, ft_presskey, map);
//	ft_game(&map);
	printf("after ft_game\n");
	mlx_loop(map->mlx);
	return (0);
}
*/
