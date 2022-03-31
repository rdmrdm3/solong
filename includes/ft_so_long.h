/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:00:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 16:51:53 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <mlx.h>
# include "../mlx/mlx.h"

// to remove
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

//struct to save how many exit(exit) and where they are (espot)
typedef struct s_map
{
	int		wall;
	int		walkway;
	int		collectible;
	int		**cspot;
	int		player;
	int		**pspot;
	int		exitout;
	int		**espot;
	int		ghost;
	int		**gspot;
	int		nbline;
	int		nbcolumn;
	char	**maze;
	int		nbmove;
	void	*mlx;
	void	*win;
	int		mv;
	int		increm;
	int		anim;
	int		pacmouth;	
}			t_map;

typedef struct s_square
{
	int	ul;
	int	up;
	int	ur;
	int	le;
	int	ce;
	int	ri;
	int	dl;
	int	dw;
	int	dr;
}	t_square;

int		ft_changedoor(t_map *map);
int		ft_checkmap(t_map **map);
int		ft_closegame(t_map **map);
void	ft_displaymap(t_map **map);
int		ft_exitfail(int fd, int i);
char	*ft_fourwall(t_square sq);
int		ft_game(t_map *map);
void	ft_initmap(t_map **map);
int		ft_inputmap(char *arg1, t_map **map);
int		ft_inputspot(t_map **map);
int		ft_isberfile(char *file);
int		ft_ispathofmapvalid(char *arg1);
char	*ft_onewall(t_square sq);
int		ft_pacup(t_map **map);
int		ft_pacmove(int mv, int l, int c, t_map **map);
int		ft_parsing(int argc, char **argv, t_map **map);
void	ft_printmap(t_map **map);
int		ft_presskey(int keycode, void *map);
void	ft_putnbmove(int n);
int		ft_readmap(char *arg1, t_map **map);
int		ft_strlen(const char *s);
char	*ft_threewall(t_square sq);
char	*ft_twowall(t_square sq);
char	*ft_whichwall(int i, int j, t_map **map);
char	*get_next_line(int fd);

// to be removed
int	ft_printmaze(t_map **map);

#endif
