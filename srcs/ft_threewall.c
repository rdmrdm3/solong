/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threewall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:27:40 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/18 11:56:34 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_threewall(t_square sq)
{
	if (sq.up == 0)
		return ("./image/wall08.xpm");
	if (sq.le == 0)
		return ("./image/wall07.xpm");
	if (sq.ri == 0)
		return ("./image/wall09.xpm");
	if (sq.dw == 0)
		return ("./image/wall10.xpm");
	return ("./image/wallfail.xpm");
}
