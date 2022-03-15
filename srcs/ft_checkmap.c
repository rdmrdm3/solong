/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:46:56 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/15 16:23:50 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

/*
static int	ft_isinlist(char c, char const *list)
{
	int	i;

	i = 0;
	while (list[i] != '\0')
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}
*/

// check the validity of the map
int	ft_checkmap(char ***map)
{
	char	***toto;

	toto = map;
/*
	int	nblines;
	int	nbcolumns;
	int	i;

	nblines = 0;
	nbcolumns = ft_strlen(map->line);
printf("nb columns = %i\n", nbcolumns);
	if (nbcolumns == 0)
		return (6);
	while (map->line != NULL)
	{
		i = 0;
		while (i < nbcolumns)
		{
			if (ft_isinlist(map->line[i], "01CEP") == 0)
				return (7);
			printf("|%i->%c|", i, map->line[i]);
			i++;
		}
		map = map->next;
		nblines++;
printf("\nnb lines =%i\n", nblines);
	}
*/
	return (1);
}
