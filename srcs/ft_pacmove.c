/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:41:40 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/30 15:43:58 by rdi-marz         ###   ########.fr       */
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

int	ft_c(int mv, int c)
{
	return (c * 25 + 25 * (mv == 2) - 25 * (mv == 4));
}

int	ft_l(int mv, int l)
{
	return (l * 25 + 25 * (mv == 3) - 25 * (mv == 1));
}

int	ft_onemove(int mv, int l, int c, int i, int j, t_map **map, char **ima)
{		
	int			w;
	int			h;
	void		*img;

	img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkwayblack.xpm", &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
	mlx_destroy_image((*map)->mlx, img);
	img = mlx_xpm_file_to_image((*map)->mlx, ima[j], &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv == 1) + i * (mv == 3));
	mlx_destroy_image((*map)->mlx, img);
	return (0);
}

int	ft_pacmove(int mv, int l, int c, t_map **map)
{
	char			**ima;

	ima = malloc(5 * sizeof(char *));
	ft_whichimage(mv, &ima);
	ft_onemove(mv, l, c, (*map)->increm, (*map)->pacmouth, map, ima);
	if ((*map)->increm == 0 || (*map)->increm == 8 || (*map)->increm == 16 || (*map)->increm == 24)
		(*map)->pacmouth++;
	if ((*map)->pacmouth == 5i || (*map)->increm == 25)
		(*map)->pacmouth = 0;
//	j += 1 - 5 * (j == 4);
	free(ima);
	return (0);
}

int	ft_pacmoveold(int mv, int l, int c, t_map **map)
{
	int				i;
	static int		j;
	char			**ima;

	j = 0;
	i = 0;
	printf("in pacmove\n");
	ima = malloc(5 * sizeof(char *));
	ft_whichimage(mv, &ima);
	while (i <= 25)
	{	
		ft_onemove(mv, l, c, i, j, map, ima);
		j += 1 - 5 * (j == 4);
		i++;
	}
	(*map)->pspot[0][1] += (mv == 2) - (mv == 4);
	(*map)->pspot[0][0] += (mv == 3) - (mv == 1);
	return (0);
}
