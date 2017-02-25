/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:43:56 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 20:37:59 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static	int		ft_return_worlds(const char *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (result);
}

static	void	ft_malloc_for_char(const char *s, char c, char ***tab)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	while (!(j = 0) && (s[i] == (const char)c))
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != (const char)c)
		{
			j++;
			i++;
		}
		if (j > 0)
		{
			(*tab)[x] = (char*)malloc(sizeof(char) * (j + 1));
			x++;
		}
		j = 0;
		i++;
	}
}

static	void	ft_insert_zero(const char *s, char c, char ***tab, int result)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (!(j = 0) && (s[i] == (const char)c))
		i++;
	while (s[i] && result > x)
	{
		while (s[i] && (s[i] != (const char)c))
		{
			(*tab)[x][j] = (char)s[i];
			i++;
			j++;
		}
		if (j > 0)
		{
			(*tab)[x][j] = '\0';
			x++;
		}
		j = 0;
		i++;
	}
	(*tab)[x] = 0;
}

char			**ft_strsplit(const char *s, char c)
{
	int		result;
	char	**tab;

	if (s == NULL)
		return (NULL);
	result = ft_return_worlds(s, c);
	tab = (char**)malloc(sizeof(char*) * (result + 1));
	if (tab != NULL)
	{
		ft_malloc_for_char(s, c, &tab);
		ft_insert_zero(s, c, &tab, result);
	}
	return (tab);
}
