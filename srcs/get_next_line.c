/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:52:49 by rdi-marz          #+#    #+#             */
/*   Updated: 2022/03/09 22:54:02 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

// Alloue avec Malloc et retourne une nouvelle chaine composee
// de s1 et des n premiers caracteres de fridge termine par \0
char	*ft_strnjoin(char **s1, char *fridge, int n)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1 != NULL && (*s1)[i] != '\0')
		i++;
	str = malloc ((i + n + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 != NULL && *s1 != NULL && *s1 && (*s1)[i] != '\0')
	{
		str[i] = (*s1)[i];
		i++;
	}
	j = -1;
	while (j++ < n - 1)
		str[i + j] = fridge[j];
	str[i + j] = '\0';
	return (str);
}

// Ajoute les caracteres avant le \n a resu
// stocke le reste dans fridge
int	ft_alloc_fridge(char **resu, char *fridge)
{
	int		i;
	int		j;
	int		k;
	int		is_bsn;
	char	*new_resu;

	i = 0;
	j = 0;
	is_bsn = 0;
	if (fridge[0] == '\0')
		return (0);
	while (fridge[i] != '\0')
		i++;
	while (fridge[j] != '\n' && j < i)
		j++;
	if (fridge[j++] == '\n')
		is_bsn = 1;
	new_resu = ft_strnjoin(resu, fridge, j);
	free(*resu);
	*resu = new_resu;
	k = 0;
	while (j < i)
		fridge[k++] = fridge[j++];
	fridge[k] = '\0';
	return (k + is_bsn);
}

char	*get_next_line(int fd)
{
	char		*resu;
	int			fridge_size;
	static char	fridge[BUFFER_SIZE + 1];
	int			nbr_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, fridge, 0))
		return (NULL);
	resu = NULL;
	fridge_size = ft_alloc_fridge(&resu, fridge);
	if (fridge_size > 0)
		return (resu);
	nbr_read = 1;
	while (fridge_size == 0 && nbr_read > 0)
	{
		nbr_read = read(fd, fridge, BUFFER_SIZE);
		fridge[nbr_read] = '\0';
		if (nbr_read <= 0)
			return (resu);
		fridge_size = ft_alloc_fridge(&resu, fridge);
	}
	return (resu);
}
