/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 12:53:18 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 14:59:39 by afeuerst         ###   ########.fr       */
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
	if (tab == NULL || path == NULL)
		return (NULL);
	while ((tmp = readdir(rep)))
	{
		if (*tmp->d_name == '.' || tmp->d_type != DT_REG)
			continue ;
		*ptr++ = ft_copy(tmp->d_name);
	}
	*ptr = NULL;
	closedir(rep);
	return (tab);
}

static char			**ft_from_path(const char *path)
{
	DIR				*rep;
	size_t			count;
	struct dirent	*tmp;

	tmp = NULL;
	count = 0;
	if (path == NULL)
		return (NULL);
	rep = opendir(path);
	if (rep == NULL)
		return (NULL);
	while ((tmp = readdir(rep)))
	{
		if (*tmp->d_name == '.' || tmp->d_type != DT_REG)
			continue ;
		count++;
	}
	closedir(rep);
	return (ft_from_npath(count, path));
}

static t_board		*ft_new(void)
{
	t_board			*new;

	new = malloc(sizeof(t_board));
	new->path = NULL;
	new->content = NULL;
	new->next = NULL;
	return (new);
}

t_board				*ft_get_bin_board(void)
{
	t_board			*board;
	t_board			*first;
	char			**split_path;
	char      *path;

	path = ft_env_for_key("PATH");
	if (path == NULL || *path == 0)
		return (NULL);
	split_path = ft_strsplit(ft_copy(path), ft_isdoublepoint);
	if (split_path == NULL || *split_path == NULL)
		return (NULL);
	board = ft_new();
	first = board;
	while (*split_path)
	{
		board->path = *split_path;
		board->content = ft_from_path(*split_path);
		split_path++;
		if (*split_path)
		{
			board->next = ft_new();
			board = board->next;
		}
	}
	return (first);
}
