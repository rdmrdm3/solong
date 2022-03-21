/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/21 11:12:10 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_so_long.h"

int	ft_game(t_map **map, t_vars vars)
{
	mlx_hook(vars.win, 17, 0L, ft_closegame(&vars), &vars);
	mlx_hook(vars.win, 2, 1L<<0, ft_presskey(&vars), &vars);
	retiurn (0);
}
