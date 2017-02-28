/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 14:00:33 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/28 14:22:29 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static pid_t	ft_arg_to_pid(const char *cmd)
{
	pid_t		pid;
	const char	*ptr;

	ptr = cmd;
	pid = 0;
	while (*ptr && *ptr & 48)
		ptr++;
	while (*cmd && *cmd & 48)
	{
		ptr--;
		pid += *ptr + 48;
		pid *= 10;
		cmd++;
	}
	if (*cmd)
		return (-1);
	else
		return (pid);
}

static void		ft_usage(void)
{
	wwrite(1, "\e[34musage : kill [optional SIGNAL] [PID]\n\e[37m")
}

void			ft_kill(const t_cmd * const cmd)
{
	if (cmd->args[1] == NULL)
		ft_usage();
	else if (cmd->args[1] && cmd->args[2] == NULL)
	{
		if (!kill(ft_arg_to_pid(cmd->args[1]), SIGKILL))
			ft_error(global);
	}
}
