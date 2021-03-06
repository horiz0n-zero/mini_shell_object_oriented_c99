/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:47:03 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:37:27 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "signal.h"

static void			ft_void(int signal)
{
	(void)signal;
	WWRITE(1, "\e[2D\e[1K$>\n$>")
}

void				ft_init_signal(void)
{
	if (signal(SIGTSTP, ft_void) == SIG_ERR)
		WWRITE(1, "\e[32mechec de l'init des signaux\n")
	if (signal(SIGINT, ft_void) == SIG_ERR)
		WWRITE(1, "\e[32echec de l'init des signaux\n")
}
