/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twowall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:25:45 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/18 12:18:17 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_twowall(t_square sq)
{
	if (sq.up == 1 && sq.dw == 1)
		return ("./image/wall01.xpm");
	if (sq.le == 1 && sq.ri == 1)
		return ("./image/wall02.xpm");
	if (sq.up == 1 && sq.ri == 1)
		return ("./image/wall03.xpm");
	if (sq.dw == 1 && sq.ri == 1)
		return ("./image/wall04.xpm");
	if (sq.dw == 1 && sq.le == 1)
		return ("./image/wall05.xpm");
	if (sq.up == 1 && sq.le == 1)
		return ("./image/wall06.xpm");
	return ("./image/wallfail.xpm");
}
