/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitfail_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:47:10 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/07 14:18:00 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// manage the additionnal message printed after Error\n
int	ft_exitfail_bonus(int fd, int i)
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
		write (fd, "Put 1 exit on the map.\n", 23);
	else if (i == 10)
		write (fd, "Put minimum 1 ghost on the map.\n", 32);
	else if (i == 11)
		write (fd, "There should be walls all around the map.\n", 42);
	return (0);
}
