/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitfail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:37:27 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/11 17:03:11 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_exitfail(int fd, int i)
{
	write(fd, "Error\n", 6);
	if (i == 2)
		write (fd, "You should input 1 argument : path/map.ber\n", 43);
	else if (i == 3)
		write (fd, "Your path for the map is invalid\n", 33);
	else if (i == 4)
		write (fd, "Your map should be a ber file\n", 30);
	else if (i == 5)
		write (fd, "An error occured while reading the map, try again\n", 50);
	else if (i == 6)
		write (fd, "i=6\n", 4);
	else if (i == 0)
		write (fd, "i=0\n", 4);
	else if (i == 1)
		write (fd, "i=1\n", 4);
	return (0);
}
