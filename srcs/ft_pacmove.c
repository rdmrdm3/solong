/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:41:40 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/04 11:30:26 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_whichimage(int mv, char ***ima)
{
	(*ima)[0] = "./image/pacman.xpm";
	if (mv == 1)
	{
		(*ima)[1] = "./image/pacman_up1.xpm";
		(*ima)[2] = "./image/pacman_up2.xpm";
	}
	if (mv == 2)
	{
		(*ima)[1] = "./image/pacman_right1.xpm";
		(*ima)[2] = "./image/pacman_right2.xpm";
	}
	if (mv == 3)
	{		
		(*ima)[1] = "./image/pacman_down1.xpm";
		(*ima)[2] = "./image/pacman_down2.xpm";
	}
	if (mv == 4)
	{		
		(*ima)[1] = "./image/pacman_left1.xpm";
		(*ima)[2] = "./image/pacman_left2.xpm";
	}
		(*ima)[3] = (*ima)[1];
		(*ima)[4] = (*ima)[0];
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

int	ft_onemove(t_map **map, char **ima)
{		
	int			w;
	int			h;
	void		*img;

	img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkwayblck.xpm", &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, (*map)->pspot[0][1] * 25, (*map)->pspot[0][0] * 25 - 0);
	mlx_destroy_image((*map)->mlx, img);
	img = mlx_xpm_file_to_image((*map)->mlx, ima[(*map)->pacmouth], &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, (*map)->pspot[0][1] * 25
		+ (*map)->increm * ((*map)->mv == 2)
		- (*map)->increm * ((*map)->mv == 4), (*map)->pspot[0][0] * 25
		- (*map)->increm * ((*map)->mv == 1)
		+ (*map)->increm * ((*map)->mv == 3));
	mlx_destroy_image((*map)->mlx, img);
	return (0);
}

int	ft_pacmove(t_map **map)
{
	char	**ima;

	ima = malloc(5 * sizeof(char *));
	ft_whichimage((*map)->mv, &ima);
	ft_onemove(map, ima);
	if ((*map)->increm == 0 || (*map)->increm == 8 || (*map)->increm == 16
		|| (*map)->increm == 24)
		(*map)->pacmouth++;
	if ((*map)->pacmouth == 5 || (*map)->increm == 25)
		(*map)->pacmouth = 0;
	free(ima);
	return (0);
}
