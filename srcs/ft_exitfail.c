/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitfail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:37:27 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/17 16:59:20 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_exitfail(int fd, int i)
{
	write(fd, "Error\n", 6);
	if (i == 2)
		write (fd, "You should input 1 argument : path/map.ber.\n", 44);
	else if (i == 3)
		write (fd, "Your path for the map is invalid.\n", 34);
	else if (i == 4)
		write (fd, "Your map should be a ber file.\n", 31);
	else if (i == 5)
		write (fd, "An error occured while reading the map, try again.\n", 51);
	else if (i == 6)
		write (fd, "The map is not rectangular.\n", 28);
	else if (i == 7)
		write (fd, "Put one player on the map.\n", 27);
	else if (i == 8)
		write (fd, "Put minimum 1 collectible on the map.\n", 38);
	else if (i == 9)
		write (fd, "Put minimum 1 exit on the map.\n", 31);
	else if (i == 10)
		write (fd, "No ghost are allowed on the map.\n", 33);
	else if (i == 11)
		write (fd, "There should be walls all around the map.\n", 42);
	return (0);
}
