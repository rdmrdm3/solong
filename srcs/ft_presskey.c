/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presskey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:53:14 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/21 16:48:07 by rdi-marz         ###   ########.fr       */
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
		ft_pacup(vars, map);
	}
	else if (keycode == 0)
		printf("you just pressed a\n");
	else if (keycode == 1)
		printf("you just pressed s\n");
	else if (keycode == 2)
		printf("you just pressed d\n");
	printf("you just pressed key number =>%i\n", keycode);
	vars = NULL;
	return (0);
}
