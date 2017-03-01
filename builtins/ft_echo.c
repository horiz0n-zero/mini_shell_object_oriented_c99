/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:18:00 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:31:52 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_echo(const t_cmd * const cmd)
{
	uint8_t	set;
	uint8_t	index;

	index = 1;
	set = 1;
	if (cmd->args[index] && !ft_strncmp(cmd->args[index], "-n", 2))
	{
		set = 0;
		index++;
	}
	while (cmd->args[index])
		write(1, cmd->args[index], ft_strlen(cmd->args[index])) && index++;
	if (set)
		write(1, "\n", 1);
}
