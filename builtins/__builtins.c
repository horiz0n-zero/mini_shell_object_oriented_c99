/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:23:20 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 17:54:35 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void				ft_exit_destructor(const t_cmd *cmd)
{
	(void)cmd;
	exit(0);
}

static void				ft_local_exe(const t_cmd * const cmd)
{
	pid_t				pid;
	extern char			**environ;

	pid = fork();
	if (pid == 0)
	{
		execve(*cmd->args, cmd->args, environ);
		write(1, *cmd->args, ft_strlen(*cmd->args));
		wwrite(1, " No such file or directory\n")
		exit(1);
	}
	else
		wait(NULL);
}

uint32_t				ft_builtins(const t_cmd * const cmd)
{
	if (!ft_strncmp(*cmd->args, "echo", 4))
	{
		ft_echo(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "cd", 2))
	{
		ft_cd(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "exit", 4))
		ft_exit_destructor(cmd);
	else if (!ft_strncmp(cmd->copy, "./", 2) || !ft_strncmp(cmd->copy, "/", 1))
	{
		ft_local_exe(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "shell", 5))
	{
		ft_shell(cmd);
		return (0);
	}
	return (1);
}
