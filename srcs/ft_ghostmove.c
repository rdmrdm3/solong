/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghostmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:15:49 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/04 11:16:24 by rdi-marz         ###   ########.fr       */
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

int	ft_c(int mv, int c)
{
	return (c * 25 + 25 * (mv == 2) - 25 * (mv == 4));
}

int	ft_l(int mv, int l)
{
	return (l * 25 + 25 * (mv == 3) - 25 * (mv == 1));
}

int	ft_onemove(int i, int l, int c, t_map **map, char **ima)
{		
	int			w;
	int			h;
	void		*img;

	i++;
	i--;
	img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkwayblck.xpm", &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
	mlx_destroy_image((*map)->mlx, img);
	img = mlx_xpm_file_to_image((*map)->mlx, ima[(*map)->pacmouth], &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25
		+ (*map)->increm * ((*map)->mv == 2)
		- (*map)->increm * ((*map)->mv == 4), l * 25
		- (*map)->increm * ((*map)->mv == 1)
		+ (*map)->increm * ((*map)->mv == 3));
	mlx_destroy_image((*map)->mlx, img);
	return (0);
}

int	ft_ghostmove(int l, int c, t_map **map)
{
	char	**imghost;
	int	i;

	i = 0;
	while (i < ghost)
	{
		imghost = malloc(3 * sizeof(char *));
		ft_whichghost((*map)->ghost[i][2], &imghost);
		ft_onemove(i, l, c, map, imghost);
		if ((*map)->increm == 0 || (*map)->increm == 24)
			(*map)->pacmouth++;
		if ((*map)->pacmouth == 2 || (*map)->increm == 25)
			(*map)->pacmouth = 0;
		i++;
	}
	free(imghost);
	return (0);
}
