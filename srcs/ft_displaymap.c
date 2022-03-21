/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaymap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:28:19 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/21 13:25:21 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_whatimage(int i, int j, t_map **map)
{
	int	c;

	c = (*map)->maze[i][j];
	if (c == '0')
		return ("./image/walkway.xpm");
	else if (c == '1')
		return (ft_whichwall(i, j, map));
	else if (c == 'C')
		return ("./image/strawberry.xpm");
	else if (c == 'E')
		return ("./image/doorclosed.xpm");
	else if (c == 'P')
		return ("./image/pacman.xpm");
	else if (c == 'G')
		return ("./image/ghost.xpm");
	return (NULL);
}

// win_width should be lower than 1920
// win_heigth should be lower than 1080
t_vars	ft_displaymap(t_map **map)
{
	void	*img;
	t_vars	vars;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	win_width = ((*map)->nbcolumn - 1) * 25;
	win_height = (*map)->nbline * 25;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, win_width, win_height, "Pacman @ 42");
	i = 0;
	while (i < (*map)->nbline)
	{
		j = 0;
		while (j < (*map)->nbcolumn - 1)
		{
			img = mlx_xpm_file_to_image(vars.mlx, ft_whatimage(i, j, map), &img_width, &img_height);
			mlx_put_image_to_window(vars.mlx, vars.win, img, j * 25, i * 25);
			j++;
		}
		i++;
	}
	mlx_loop(vars);
	return (vars);
}
