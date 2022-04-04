/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:12:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/04/02 21:12:55 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_nblen(int n)
{
	unsigned int	j;
	int				neg;

	neg = 0;
	if (n < 0)
	{
		j = (unsigned int)(-n);
		neg = 1;
	}
	else
		j = (unsigned int)n;
	if (j <= 9)
		return (1 + neg);
	else
		return (ft_nblen(j / 10) + 1 + neg);
}

// Alloue (avec malloc(3)) et retourne une chaine de caractères représentant
// l’integer reçu en argument. Les nombres négatifs doivent être gérés.
char	*ft_itoa(int n)
{
	char			*resu;
	unsigned int	j;
	int				nbl;

	nbl = ft_nblen(n);
	resu = malloc((nbl + 1) * sizeof(char));
	if (!resu)
		return (NULL);
	if (n < 0)
	{
		resu[0] = '-';
		j = (unsigned int)(-n);
	}
	else
		j = (unsigned int)n;
	resu[nbl--] = '\0';
	if (n == 0)
		resu[0] = '0';
	while (j > 0)
	{
		resu[nbl] = j % 10 + '0';
		j = j / 10;
		nbl--;
	}
	return (resu);
}
