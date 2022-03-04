/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:30:11 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/04 17:15:11 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./image/img01.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_loop(mlx);
}
