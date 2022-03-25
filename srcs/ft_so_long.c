/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:38:30 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/25 09:42:52 by rdi-marz         ###   ########.fr       */
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
	printf("after parsing\n");
	ft_displaymap(&map);
	printf("after displaymap\n");
	ft_game(&map);
	printf("after ft_game\n");
	mlx_loop(map->mlx);
	return (0);
}
