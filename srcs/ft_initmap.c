/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:06:29 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/17 14:35:40 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_initmap(t_map **map)
{
	(*map)->wall = 0;
	(*map)->walkway = 0;
	(*map)->collectible = 0;
	(*map)->player = 0;
	(*map)->exit = 0;
	(*map)->ghost = 0;
	(*map)->nbline = 0;
	(*map)->nbcolumn = 0;
	(*map)->maze = NULL;
}
