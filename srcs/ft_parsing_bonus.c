/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:36:12 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/07 15:15:06 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// check if the parameters given to the program are valid
int	ft_parsing_bonus(int argc, char **argv, t_map **map)
{
	int	i;

	if (argc != 2)
		return (2);
	if (ft_ispathofmapvalid(argv[1]) != 1)
		return (3);
	if (ft_isberfile(argv[1]) != 1)
		return (4);
	ft_initmap(map);
	i = ft_readmap(argv[1], map);
	if (i != 1)
		return (i);
	i = ft_checkmap_bonus(map);
	if (i != 1)
		return (i);
	if ((*map)->errchar != 0)
		return (12);
	return (1);
}
