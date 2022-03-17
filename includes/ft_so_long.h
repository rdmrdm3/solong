/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:00:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/16 21:14:38 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// to remove
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

//typedef struct s_map
//{
//	char			*line;
//	struct s_map	*next;
//}	t_map;

typedef struct s_map
{
	int		wall;
	int		walkway;
	int		collectible;
	int		player;
	int		exit;
	int		nbline;
	int		nbcolumn;
	char	**maze;
}	t_map;

int		ft_checkmap(char ***map);
int		ft_exitfail(int fd, int i);
int		ft_isberfile(char *file);
int		ft_ispathofmapvalid(char *arg1);
int		ft_parsing(int argc, char **argv, char ***map);
int		ft_readmap(char *arg1, char ***map);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
