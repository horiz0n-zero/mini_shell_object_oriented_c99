/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:17:23 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 13:19:06 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char				*ft_stc_pluslash(const char *str)
{
	static char		buffer[1024];
	char			*ptr;

	ptr = buffer;
	ft_memset_ll(buffer, 0, 1024/8);
	while (*str)
		*ptr++ = *str++;
	*ptr = '/';
	return (buffer);
}
