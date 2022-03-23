/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/23 11:58:39 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_presskey(int keycode, t_vars *vars, t_map **map)
{
	if (keycode == 53)
		printf("you just pressed escape :)\n");
	else if (keycode == 13)
	{
		printf("you just pressed w\n");
		ft_pacmove(1, (*map)->pspot[0][0], (*map)->pspot[0][1], &vars);
	}
	else if (keycode == 0)
	{
		printf("you just pressed a\n");
		ft_pacmove(4, (*map)->pspot[0][0], (*map)->pspot[0][1], &vars);
	}
	else if (keycode == 1)
	{
		printf("you just pressed s\n");
		ft_pacmove(3, (*map)->pspot[0][0], (*map)->pspot[0][1], &vars);
	}
	else if (keycode == 2)
	{
		printf("you just pressed d\n");
		ft_pacmove(2, (*map)->pspot[0][0], (*map)->pspot[0][1], &vars);
	}
	printf("you just pressed key number =>%i\n", keycode);
	vars = NULL;
	return (0);
}
