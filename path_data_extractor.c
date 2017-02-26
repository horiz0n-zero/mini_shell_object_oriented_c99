/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_data_extractor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 22:49:48 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 23:13:25 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char			**ft_from_npath(const size_t n, const char *path)
{
	char			**tab;
	char			**ptr;
	DIR				*rep;
	struct dirent	*tmp;

	tmp = NULL;
	rep = opendir(path);
	tab = malloc(sizeof(char*) * (n + 1));
	ptr = tab;
	while ((tmp = readdir(rep)))
		*ptr++ = ft_copy(tmp->d_name);
	*ptr = NULL;
	closedir(rep);
	return (tab);
}

static char			**ft_from_path(const char *path)
{
	DIR				*rep;
	struct dirent	*tmp;
	size_t			count;

	count = 0;
	tmp = NULL;
	rep = opendir(path);
	if (rep == NULL)
		return (NULL);
	while ((tmp = readdir(rep)))
		count++;
	closedir(rep);
	return (ft_from_npath(count, path));
}

static char			**ft_data(char **path)
{

	return (NULL);
}

char				**ft_path_data(void)
{
	char			*data;
	char			**path;

	data = getenv("PATH");
	if (data == NULL)
		return (NULL);
	path = ft_strsplit(data, ft_isdoublepoint);
	if (path == NULL)
		return (NULL);
	return (ft_data(path));
}
