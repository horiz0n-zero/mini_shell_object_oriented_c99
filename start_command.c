/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:57:22 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:51:00 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int64_t		ft_typeofpath_(t_board **board, t_board **save, const int i)
{
	if (i == 42)
	{
		*board = ft_get_bin_board();
		*save = *board;
	}
	else if  (*board == NULL)
	{
		*board = ft_get_bin_board();
		*save = *board;
	}
	else if (i == 1)
		return (1);
	return (0);
}

static int			ft_w(t_board **board, t_board **save, char *bin, char **dst)
{
	int				i;

	i = 0;
	while ((*board)->content[i])
	{
		if (!ft_strncmp(bin, (*board)->content[i], LEN((*board)->content[i])))
		{
			*dst = SJOIN(SLASH((*board)->path), (*board)->content[i]);
			*board = *save;
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int64_t				ft_typeofpath(const char *bin_path, char **dst, const int i)
{
	static t_board	*board = NULL;
	static t_board	*save = NULL;

	if (ft_typeofpath_(&board, &save, i))
		return ((int64_t)save);
	while (board)
	{
		if (board->content == NULL)
		{
			board = board->next;
			continue ;
		}
		if (ft_w(&board, &save, (char*)bin_path, dst))
			return (1);
		board = board->next;
	}
	board = save;
	return (-1);
}

static void			ft_launch_command(const t_cmd * const cmd, const char *bin_path)
{
	pid_t			pid;
	extern char		**environ;
	int				status;

	pid = fork();
	if (!pid)
	{
		execve(bin_path, cmd->args, environ);
		ft_error(global);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
	if (status)
		ft_signal(status, pid, *cmd->args);
}

void				ft_start_command(const t_cmd * const cmd)
{
	int64_t			typeof_path;
	char			*bin_path;

	bin_path = NULL;
	typeof_path = ft_typeofpath(*cmd->args, &bin_path, 0);
	if (typeof_path < 0)
	{
		WWRITE(1, "\e[31m Command not found : ")
		write(1, *cmd->args, ft_strlen(*cmd->args));
		write(1, "\e[37m\n", sizeof("\e[37m\n"));
	}
	else
	{
		if (bin_path)
			ft_launch_command(cmd, bin_path);
	}
}
