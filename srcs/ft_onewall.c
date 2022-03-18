/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onewall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:20:46 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/18 11:39:49 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_onewall(t_square sq)
{
	if (sq.up == 1)
		return ("./image/wall12.xpm");
	if (sq.le == 1)
		return ("./image/wall15.xpm");
	if (sq.ri == 1)
		return ("./image/wall13.xpm");
	if (sq.dw == 1)
		return ("./image/wall14.xpm");
	return ("./image/wallfail.xpm");
}
