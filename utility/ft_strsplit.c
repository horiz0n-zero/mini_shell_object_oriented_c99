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

#include "shell.h"

size_t	ft_count(const char *str, int (*f)(int))
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (f(*str))
			while (f(*str))
				str++;
		if (*str == '\0')
			break ;
		count++;
		while (*str && !f(*str))
			str++;
	}
	return (count);
}

char	**ft_strsplit(char *str, int (*f)(int))
{
	char	**tab;
	char	**ptr;

	tab = malloc(sizeof(char*) * (ft_count(str, f) + 1));
	ptr = tab;
	while (*str)
	{
		if (*str && !f(*str))
		{
			*tab = str;
			while (*str && !f(*str))
				str++;
			*str++ = 0;
			tab++;
		}
		if (*str && f((int)*str))
			while (*str && f(*str))
				*str++ = '\0';
	}
	*tab = NULL;
	return (ptr);
}
