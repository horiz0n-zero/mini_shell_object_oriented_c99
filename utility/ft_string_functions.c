/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:11:52 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 23:03:35 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
