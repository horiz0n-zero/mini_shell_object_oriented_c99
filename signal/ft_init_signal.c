/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:47:03 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 18:05:34 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "signal.h"

void				ft_init_signal(void)
{
	if (signal(SIGSEGV, SIG_DFL) == SIG_ERR)
		wwrite(1, "\e[32mechec de l'init des signaux segfaults.\n")
}
