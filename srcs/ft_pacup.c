/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:15:00 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/22 09:00:48 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_pacup(t_vars	*vars, t_map **map)
{
	void	*img;
	int		img_width;
	int		img_height;
	int 	i;

printf("1\n");
	i = 1;
printf("2\n");
	while (i < 9)
	{
printf("3\n");
		img = mlx_xpm_file_to_image(vars->mlx, "../image/pacman_up1.xpm", &img_width, &img_height);
printf("4\n");
		mlx_put_image_to_window(vars->mlx, vars->win, img, 3 * 25, 3 * 25 - i);
printf("5\n");
		i++;
printf("6\n");
	}
printf("7\n");
	
	i = 8;
	while (i < 17)
	{
		img = mlx_xpm_file_to_image(vars->mlx, "../image/pacman_up2.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, 3 * 25, 3 * 25 - i);
		i++;
	}
	
	i = 17;
	while (i < 25)
	{
		img = mlx_xpm_file_to_image(vars->mlx, "../image/pacman_up1.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, img, 3 * 25, 3 * 25 - i);
		i++;
	}
	return (0);
	i = (*map)->wall;
	return (0);
}
