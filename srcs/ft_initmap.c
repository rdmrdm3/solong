/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:06:29 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 13:16:19 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_initmap(t_map **map)
{
	(*map)->wall = 0;
	(*map)->walkway = 0;
	(*map)->collectible = 0;
	(*map)->cspot = NULL;
	(*map)->player = 0;
	(*map)->pspot = NULL;
	(*map)->exit = 0;
	(*map)->espot = NULL;
	(*map)->ghost = 0;
	(*map)->gspot = NULL;
	(*map)->nbline = 0;
	(*map)->nbcolumn = 0;
	(*map)->maze = NULL;
	(*map)->nbmove = 0;
	(*map)->key = -1;
	(*map)->increm = 0;
}
