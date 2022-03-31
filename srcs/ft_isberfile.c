/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isberfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:46:58 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/31 12:08:39 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// check if the name of the file ends with .ber
int	ft_isberfile(char *file)
{
	int	file_len;

	file_len = ft_strlen(file);
	if (file[file_len - 4] != '.')
		return (4);
	if (file[file_len - 3] != 'b')
		return (4);
	if (file[file_len - 2] != 'e')
		return (4);
	if (file[file_len - 1] != 'r')
		return (4);
	return (1);
}
