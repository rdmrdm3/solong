/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testminilibx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:49:57 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/08 09:50:02 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

/*
// open a window
int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 192, 108, "Hello world!");
	mlx_loop(mlx);
}
*/

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	// After creating an image, we can call `mlx_get_data_addr`, we pass
	// `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// then be set accordingly for the *current* data address.
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb_uc(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t_uc(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r_uc(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g_uc(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b_uc(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	ft_drawsquare(t_data *g, int x, int y, int size, unsigned long int color)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		my_mlx_pixel_put(g, x, y + i, color);
		my_mlx_pixel_put(g, x + size, y + i, color);
		my_mlx_pixel_put(g, x + i, y, color);
		my_mlx_pixel_put(g, x + i, y + size, color);
		i++;
	}
	return (0);
}

int	ft_drawsquarefull(t_data *g, int x, int y, int size, unsigned long int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	color = 0;
	while (i <= size)
	{
		while (j <= size)
		{
			my_mlx_pixel_put(g, x + i, y + j, create_trgb(0, i, j, 0));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_drawsquarefull(&img, 0, 0, 255, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
