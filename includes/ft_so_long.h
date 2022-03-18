/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:00:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/18 08:44:00 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

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

typedef struct s_map
{
	int		wall;
	int		walkway;
	int		collectible;
	int		player;
	int		exit;
	int		ghost;
	int		nbline;
	int		nbcolumn;
	char	**maze;
}			t_map;

typedef struct s_square
{
	int	ul;
	int	up;
	int	ur;
	int	le;
	int	ce;
	int ri;
	int dl;
	int	dw;
	int	dr;
}	t_square

int		ft_checkmap(t_map **map);
int		ft_displaymap(t_map **map);
int		ft_exitfail(int fd, int i);
void	ft_initmap(t_map **map);
int		ft_isberfile(char *file);
int		ft_ispathofmapvalid(char *arg1);
int		ft_parsing(int argc, char **argv, t_map **map);
void	ft_printmap(t_map **map);
int		ft_readmap(char *arg1, t_map **map);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
