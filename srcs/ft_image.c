/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:30:11 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/07 15:58:38 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}			t_vars;

int	main(void)
{
	void	*img;
	char	*relative_path = "./image/wall04.xpm";
	int		img_width;
	int		img_height;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 300, 300, "show me that xpm");
	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 10, 10);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall02.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 35, 10);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall02.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 60, 10);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall05.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 85, 10);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall01.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 10, 35);

	img = mlx_xpm_file_to_image(vars.mlx, "./image/circle.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 35, 35);
	
	img = mlx_xpm_file_to_image(vars.mlx, "./image/walkway.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 60, 35);
	
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall01.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 85, 35);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall03.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 10, 60);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall02.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 35, 60);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall02.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 60, 60);
	img = mlx_xpm_file_to_image(vars.mlx, "./image/wall06.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 85, 60);
	mlx_loop(vars.mlx);
}
