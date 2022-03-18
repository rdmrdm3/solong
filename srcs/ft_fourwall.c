/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourwall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:28:08 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/18 12:03:55 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_fourwall(t_square sq)
{
	if (sq.ur + sq.ul + sq.dr + sq.dl == 4)
		return ("./image/wall16.xpm");
	if (sq.ur + sq.ul + sq.dr + sq.dl == 0)
		return ("./image/wall11.xpm");
	return ("./image/wallfail.xpm");
}
