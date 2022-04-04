/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghostmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:15:49 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/04 12:41:10 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_whichghost(int mv, char ***ima)
{
	(*ima)[0] = "./image/ghost.xpm";
	if (mv == 1)
	{
		(*ima)[1] = "./image/ghost_up.xpm";
	}
	if (mv == 2)
	{
		(*ima)[1] = "./image/ghost_right.xpm";
	}
	if (mv == 3)
	{		
		(*ima)[1] = "./image/ghost_down.xpm";
	}
	if (mv == 4)
	{		
		(*ima)[1] = "./image/ghost_left.xpm";
	}
		(*ima)[2] = (*ima)[0];
	return (0);
}

/*
int	ft_c(int mv, int c)
{
	return (c * 25 + 25 * (mv == 2) - 25 * (mv == 4));
}

int	ft_l(int mv, int l)
{
	return (l * 25 + 25 * (mv == 3) - 25 * (mv == 1));
}
*/

int	ft_onegmove(int i, t_map **map, char **ima)
{		
	int			w;
	int			h;
	void		*img;

	img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkwayblck.xpm", &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, (*map)->gspot[i][1]
		* 25, (*map)->gspot[i][0] * 25);
	mlx_destroy_image((*map)->mlx, img);
	img = mlx_xpm_file_to_image((*map)->mlx, ima[(*map)->ghostmouth], &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, (*map)->gspot[i][1]
		* 25 + (*map)->increm * ((*map)->mv == 2)
		- (*map)->increm * ((*map)->mv == 4), (*map)->gspot[i][0] * 25
		- (*map)->increm * ((*map)->mv == 1)
		+ (*map)->increm * ((*map)->mv == 3));
	mlx_destroy_image((*map)->mlx, img);
	return (0);
}

int	ft_ghostmove(t_map **map)
{
	char	**imghost;
	int		i;

	i = 0;
	while (i < (*map)->ghost)
	{
		imghost = malloc(3 * sizeof(char *));
		ft_whichghost((*map)->gspot[i][2], &imghost);
		ft_onegmove(i, map, imghost);
		if ((*map)->increm == 0 || (*map)->increm == 24)
			(*map)->ghostmouth++;
		if ((*map)->ghostmouth == 2 || (*map)->increm == 25)
			(*map)->ghostmouth = 0;
		i++;
	}
	free(imghost);
	return (0);
}
