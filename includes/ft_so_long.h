/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:00:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/10 21:58:05 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_map
{
	char	*line;
	t_map	*next;
}	t_map;

int		ft_exitfail(int fd, int i);
int		ft_parsing(void);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
