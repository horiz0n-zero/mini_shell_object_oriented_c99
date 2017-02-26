/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:43:56 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 14:43:34 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t		ft_count(const char *str, int (*f)(int))
{
	size_t			count;

	count = 1;
	while (*str)
	{
		if (f(*str))
		{
			while (*str && f(*str))
				str++;
		}
		else
		{
			while (*str && !f(*str))
				str++;
			count++;
		}
	}
	return (count);
}

char				**ft_strsplit(char *str, int (*f)(int))
{
	char			**ptr;
	char			**tab;

	tab = NULL;
	ptr = NULL;
	tab = malloc(sizeof(char*) * (ft_count(str, f)));
	ptr = tab;
	if (ptr == NULL || tab == NULL)
		return (NULL);
	while (*str)
	{
		if (f(*str))
		{
			while (*str && f(*str))
				*str++ = 0;
		}
		else
		{
			*ptr++ = str;
			while (*str && !f(*str))
				str++;
		}
	}
	*ptr = NULL;
	return (tab);
}
