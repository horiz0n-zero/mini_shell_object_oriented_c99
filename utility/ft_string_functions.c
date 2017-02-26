/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:11:52 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 14:07:31 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while ((s2[i] || s1[i]) && (len > i))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	else
		return (1);
}

char			*ft_copy(const char *str)
{
	char		*ptr;
	char		*s;

	s = malloc(ft_strlen(str) + 1);
	ptr = s;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (s);
}

size_t			ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char			*ft_stc_strjoin(const char *s1, const char *s2)
{
	static char	buffer[1024];
	char		*ptr;

	ptr = buffer;
	ft_memset_ll(buffer, 0, 1024/8);
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (buffer);
}
