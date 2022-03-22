/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:33:47 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/22 12:03:06 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	deal_key(int key, void *param);
void	ft_draw_sprite(int w, t_vars *var);

typedef struct s_tex
{
	void	*img;
	void	*buffer;
	int		h;
	int 	w;
}	t_tex;

//back, wall, player, exit ?
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
//position joueur
	int		xpos;
	int		ypos;
	t_tex 	sprite[6];
	int		fps;
	int		frame;
	char	**map;
}	t_vars;

void	put_image(t_vars vars, char c)
{
	if (c == '1')
		ft_draw_sprite(1, &vars);
	if (c == '0')
		ft_draw_sprite(0, &vars);
	if (c == 'P')
		ft_draw_sprite(2, &vars);
	if (c == 'C')
		ft_draw_sprite(3, &vars);
	if (c == 'E')
		ft_draw_sprite(4, &vars);
}

void	ft_draw_sprite(int w, t_vars *var)
{
	int	h;
	int	l;

	if (w == 2 || w == 3 || w == 4)
	{
		var->img = mlx_xpm_file_to_image(var->mlx, var->sprite[0], &h, &l);
		mlx_put_image_to_window(var->mlx, var->win, var->img, var->mx, var->my);
		mlx_destroy_image(var->mlx, var->img);
		var->img = mlx_xpm_file_to_image(var->mlx, var->sprite[w], &h, &l);
		mlx_put_image_to_window(var->mlx, var->win, var->img, var->mx, var->my);
		return ;
	}
	var->img = mlx_xpm_file_to_image(var->mlx, var->sprite[w], &h, &l);
	mlx_put_image_to_window(var->mlx, var->win, var->img, var->mx, var->my);
}

void	put_sprite(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->mx = 0;
	vars->my = 0;
	while (map[i] != '\0')
	{
		while (map[i][j])
		{
			put_image(*vars, map[i][j]);
			j++;
			vars->mx += 64;
		}
		vars->my += 64;
		vars->mx = 0;
		j = 0;
		i++;
	}
}

void	init_sprite(t_vars *vars)
{
	vars->sprite[0].img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/sp1.xpm", &vars->sprite[0].w, &vars->sprite[0].h);
	vars->sprite[1].img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/sp2.xpm", &vars->sprite[1].w, &vars->sprite[1].h);
	vars->sprite[2].img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/sp3.xpm", &vars->sprite[2].w, &vars->sprite[2].h);
	vars->sprite[3].img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/sp4.xpm", &vars->sprite[3].w, &vars->sprite[3].h);
	vars->sprite[4].img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/sp5.xpm", &vars->sprite[4].w, &vars->sprite[4].h);
	vars->sprite[5].img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/sp6.xpm", &vars->sprite[5].w, &vars->sprite[5].h);
}

int looping(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite[vars->frame].img, 0, 0);
	if (vars->fps % 9 == 0)
		vars->frame++;
	if (vars->frame == 3)
		vars->frame = 0;
	if (vars->fps < 60)
		vars->fps++;
	else
		vars->fps = 0;
	return (1);
}

int	win_closed(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("\033[0;32m" "Window closed succesfuly!\n" "\033[0m");
	exit (0);
}

void	game_init(t_vars *vars)
{
	int w;
	int h;
	
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * 64, vars->height * 64, "So_Long");
	init_sprite(vars);
	printf("%d %d\n", w, h);
	put_sprite(vars->map, vars);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./images/Sprite/grace.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite[vars->frame].img, 0, 0);
	mlx_key_hook(vars->win, deal_key, (void *)0);
	mlx_hook(vars->win, 17, 1L << 0, win_closed, vars);
	mlx_loop_hook(vars->mlx, looping, vars);
	mlx_key_hook(vars->win, movep, vars);
	printf("%d\n",vars->fps);
	mlx_loop(vars->mlx);
	//mlx_destroy_image();
}

int	deal_key(int key, void *param)
{
	(void) param;
	if (key == 53)
	{
		printf("\033[0;32m" "Window closed successfuly!\n" "\033[0m");
		exit(0);
	}
	return (0);
}

int main()
{
	/*int	deal_key(int key, void *param)
{
	(void) param;
	if (key == 53)
	{
		ft_printf("\033[0;32m" "Window closed successfuly!\n" "\033[0m");
		exit(0);
	}
	return (0);
}*/
}
