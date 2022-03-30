/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changedoor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:02:17 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/30 15:45:13 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_changedoor(t_map *map)
{
	int			w;
	int			h;
	void		*img;

	img = mlx_xpm_file_to_image(map->mlx, "./image/dooropen.xpm", &w, &h);
	mlx_put_image_to_window(map->mlx, map->win, img, 25 * map->espot[0][1], 25 * map->espot[0][0]);
	mlx_destroy_image(map->mlx, img);
	return (0);
}
