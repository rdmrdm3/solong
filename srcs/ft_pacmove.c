/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:41:40 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/23 15:51:45 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_whichimage(int mv, char*** ima)
{
	if (mv == 1)
	{
		(*ima)[0] = "./image/pacman.xpm";
		(*ima)[1] = "./image/pacman_up1.xpm";
		(*ima)[2] = "./image/pacman_up2.xpm";
	}
	if (mv == 2)
	{
		(*ima)[0] = "./image/pacman.xpm";
		(*ima)[1] = "./image/pacman_right1.xpm";
		(*ima)[2] = "./image/pacman_right2.xpm";
	}
	if (mv == 3)
	{		
		(*ima)[0] = "./image/pacman.xpm";
		(*ima)[1] = "./image/pacman_down1.xpm";
		(*ima)[2] = "./image/pacman_down2.xpm";
	}
	if (mv == 4)
	{		
		(*ima)[0] = "./image/pacman.xpm";
		(*ima)[1] = "./image/pacman_left1.xpm";
		(*ima)[2] = "./image/pacman_left2.xpm";
	}
		(*ima)[3] = (*ima)[1];
		(*ima)[4] = (*ima)[0];
	return (0);
}

int	ft_c(int mv, int c)
{
//	printf("c=%i, mv=%i, ft_c=%i \n", c, mv, (c * 25  - 25 * (mv == 2) + 25 * (mv == 4)));
	return (c * 25  - 25 * (mv == 2) + 25 * (mv == 4));
}

int	ft_l(int mv, int l)
{
//	printf("l=%i, mv=%i, ft_l=%i \n", l, mv, (l * 25  - 25 * (mv == 3) + 25 * (mv == 1)));
	return (l * 25  - 25 * (mv == 3) + 25 * (mv == 1));
}

int	ft_pacmove(int mv, int l, int c, t_vars *vars)
{
	int		i;
	char	**ima;
	void	*img;
	int		img_width;
	int		img_height;

printf("in pacmove\n");	
	ima = malloc(5 * sizeof(char *));
	ft_whichimage(mv , &ima);
	i = 1;
	while (i < 9)
	{
		img = mlx_xpm_file_to_image(vars->mlx, "./image/walkway.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25, l * 25 - 0);
		mlx_put_image_to_window(vars->mlx, vars->win, img, ft_c(mv, c), ft_l(mv, l));
//printf("c*25=%i, l*25=%i, ftc=%i, ftl=%i, mv=%i\n", c*25, l*25, ft_c(mv, c), ft_l(mv, l), mv);
		img = mlx_xpm_file_to_image(vars->mlx, ima[1], &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv ==1) + i * (mv ==3));
		mlx_destroy_image(vars->mlx, img);
		i++;
	}
	i = 8;
	while (i < 17)
	{
		img = mlx_xpm_file_to_image(vars->mlx, "./image/walkway.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25, l * 25 - 0);
		mlx_put_image_to_window(vars->mlx, vars->win, img, ft_c(mv, c), ft_l(mv, l));
		img = mlx_xpm_file_to_image(vars->mlx, ima[2], &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv ==1) + i * (mv ==3));
		i++;
	}
	i = 17;
	while (i < 25)
	{
		img = mlx_xpm_file_to_image(vars->mlx, "./image/walkway.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25, l * 25 - 0);
		mlx_put_image_to_window(vars->mlx, vars->win, img, ft_c(mv, c), ft_l(mv, l));
		img = mlx_xpm_file_to_image(vars->mlx, ima[3], &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv ==1) + i * (mv ==3));
		i++;
	}
	img = mlx_xpm_file_to_image(vars->mlx, "./image/walkway.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25, l * 25 - 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img, ft_c(mv, c), ft_l(mv, l));
	img = mlx_xpm_file_to_image(vars->mlx, "./image/pacman.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv ==1) + i * (mv ==3));
	return (0);
}

