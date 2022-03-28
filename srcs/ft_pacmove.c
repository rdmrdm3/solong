/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:41:40 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/28 14:25:28 by acolin           ###   ########.fr       */
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
	return (c * 25 - 25 * (mv == 2) + 25 * (mv == 4));
}

int	ft_l(int mv, int l)
{
	return (l * 25 - 25 * (mv == 3) + 25 * (mv == 1));
}

int	ft_onemove(int mv, int l, int c, int i, int j, t_map **map, char **ima)
{		
	printf("%d\n", j);
	int			w;
	int			h;
	void		*img;

	img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkway.xpm", &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, ft_c(mv, c), 
			ft_l(mv, l));	
	mlx_destroy_image((*map)->mlx, img);
	img = mlx_xpm_file_to_image((*map)->mlx, ima[j], &w, &h);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25 + i * 
			(mv == 2) - i * (mv == 4), l * 25 - i * (mv == 1) + i * (mv == 3));
	mlx_destroy_image((*map)->mlx, img);
	return (0);
}

int	ft_pacmove(int mv, int l, int c, t_map **map)
{
	int				i;
	char			**ima;

	i = 0;
	printf("in pacmove\n");
	ima = malloc(5 * sizeof(char *));
	ft_whichimage(mv, &ima);
	ft_onemove(mv, l, c, (*map)->increm, (*map)->frame, map, ima);
	if ((*map)->increm % 5)
		(*map)->frame++;
	if ((*map)->frame == 5)
		(*map)->frame = 0;
	//j += 1 - 5 * (j == 4);
	return (0);
}

int	ft_pacmoveold(int mv, int l, int c, t_map **map)
{
	int				i;
	static int		j = 0;
	char			**ima;
	void			*img;
	int				img_width;
	int				img_height;

	if (j == 4)
		j = 0;
	printf("in pacmove\n");
	ima = malloc(5 * sizeof(char *));
	ft_whichimage(mv, &ima);
	i = 1;
	while (i < 9)
	{
		img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkway.xpm", &img_width, &img_height);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, ft_c(mv, c), ft_l(mv, l));
//printf("c*25=%i, l*25=%i, ftc=%i, ftl=%i, mv=%i\n", c*25, l*25, ft_c(mv, c), ft_l(mv, l), mv);
		img = mlx_xpm_file_to_image((*map)->mlx, ima[1], &img_width, &img_height);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv == 1) + i * (mv == 3));
		mlx_destroy_image((*map)->mlx, img);
		i++;
	}
	i = 8;
	while (i < 17)
	{
		img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkway.xpm", &img_width, &img_height);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, ft_c(mv, c), ft_l(mv, l));
		img = mlx_xpm_file_to_image((*map)->mlx, ima[2], &img_width, &img_height);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv == 1) + i * (mv == 3));
		i++;
	}
	i = 17;
	while (i < 25)
	{
		img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkway.xpm", &img_width, &img_height);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, ft_c(mv, c), ft_l(mv, l));
		img = mlx_xpm_file_to_image((*map)->mlx, ima[3], &img_width, &img_height);
		mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv == 1) + i * (mv == 3));
		i++;
	}
	img = mlx_xpm_file_to_image((*map)->mlx, "./image/walkway.xpm", &img_width, &img_height);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25, l * 25 - 0);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, ft_c(mv, c), ft_l(mv, l));
	img = mlx_xpm_file_to_image((*map)->mlx, "./image/pacman.xpm", &img_width, &img_height);
	mlx_put_image_to_window((*map)->mlx, (*map)->win, img, c * 25 + i * (mv == 2) - i * (mv == 4), l * 25 - i * (mv == 1) + i * (mv == 3));
	return (0);
}
