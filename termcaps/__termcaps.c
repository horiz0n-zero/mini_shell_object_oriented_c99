/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __termcaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:46:50 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/28 15:38:36 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void ft_init_termcaps(void)
{
	char            *current_term;
	struct termios  term;

	current_term = ft_env_for_key("TERM");
	if (current_term == NULL)
	{
		wwrite(1, "impossible d'init les termcaps, term not found\n")
			return ;
	}
	(void)term;
}
