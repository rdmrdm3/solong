/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:47:23 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 17:38:51 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// Écrit l’integer ’n’
void	ft_putnbmove(int n)
{
	unsigned int	i;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		i = (unsigned int)(-n);
	}
	else
		i = (unsigned int)n;
	if (i / 10 != 0)
		ft_putnbmove((int)(i / 10));
	c = i % 10 + '0';
	write(1, &c, 1);
}
