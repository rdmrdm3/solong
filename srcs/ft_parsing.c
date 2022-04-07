/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:56:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/07 15:15:09 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// check if the parameters given to the program are valid
int	ft_parsing(int argc, char **argv, t_map **map)
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
	i = ft_checkmap(map);
	if (i != 1)
		return (i);
	if ((*map)->errchar != 0)
		return (12);
	return (1);
}
