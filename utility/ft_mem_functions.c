/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:04:53 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 16:09:13 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_memset_ll(void * const ptr, const uint64_t val, size_t len)
{
	uint64_t	*ptr_ll;

	ptr_ll = (uint64_t*)ptr;
	while (len-- > 0)
		*ptr_ll++ = val;
}

void			ft_memset(void * const ptr, const uint8_t val, size_t len)
{
	uint8_t		*c_ptr;

	c_ptr = (uint8_t*)ptr;
	while (len-- > 0)
		*c_ptr++ = val;
}
