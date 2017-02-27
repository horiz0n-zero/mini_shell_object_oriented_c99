/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:23:20 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 17:28:41 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static uint32_t			ft_not_denied(const char *cmd)
{
	extern t_info		g_info;

	if (g_info.restricted)
	{
		wwrite(1, "\e[31m")
		write(1, cmd, ft_strlen(cmd));
		wwrite(1, " : Command denied\n\e[37m")
		return (0);
	}
	else
		return (1);
}

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
		wwrite(1, ": No such file or directory\n")
		exit(1);
	}
	else
		wait(NULL);
}

static uint32_t			ft_builtins_(const t_cmd * const cmd)
{
	if (!ft_strncmp(*cmd->args, "env", 3))
	{
		if (ft_not_denied("env"))
			ft_env(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "unsetenv", 8))
	{
		if (ft_not_denied("unsetenv"))
			ft_unsetenv(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "setenv", 7))
	{
		if (ft_not_denied("setenv"))
			ft_setenv(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "debug", 6))
	{
		//ft_fx(click_start);
		return (0);
	}
	return (1);
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
		if (ft_not_denied("cd"))
			ft_cd(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "exit", 4))
	{
		if (ft_not_denied("exit"))
			ft_exit_destructor(cmd);
		else
			return (0);
	}
	else if (!ft_strncmp(cmd->copy, ".", 1) || !ft_strncmp(cmd->copy, "/", 1))
	{
		if (ft_not_denied(cmd->copy))
			ft_local_exe(cmd);
		return (0);
	}
	else if (!ft_strncmp(*cmd->args, "shell", 5))
	{
		ft_shell(cmd);
		return (0);
	}
	else
		return (ft_builtins_(cmd));
	return (1);
}
