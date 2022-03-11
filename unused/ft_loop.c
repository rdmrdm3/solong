/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:26:27 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/04 15:30:04 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// not tested
#include <mlx.h>

int	render_next_frame(void *YourStruct);
{
}

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_loop_hook(mlx, render_next_frame, YourStruct);
	mlx_loop(mlx);
}
