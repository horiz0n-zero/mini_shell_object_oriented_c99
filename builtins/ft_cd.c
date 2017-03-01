/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:28:19 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 20:42:57 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static uint32_t		ft_move_back(const int set, char *buffer)
{
	extern t_info	g_info;

	if (set)
	{
		if (g_info.last_pwd)
			chdir(g_info.last_pwd);
		return (1);
	}
	else
	{
		if (g_info.last_pwd && buffer)
		{
			free(g_info.last_pwd);
			g_info.last_pwd = ft_copy(buffer);
		}
		else
			g_info.last_pwd = NULL;
		return (0);
	}
	return (0);
}

static char			*ft_cd_join(const char *position, const char *moveto)
{
	static char		buffer[8096];
	char			*ptr;

	ptr = buffer;
	ft_memset_ll(buffer, 0, 1012);
	while (*position)
		*ptr++ = *position++;
	*ptr++ = '/';
	while (*moveto)
		*ptr++ = *moveto++;
	return (buffer);
}

static void	ft_go_home(void)
{
	char	*user;

	user = ft_env_for_key("USER");
	if (user == NULL)
	{
		//WWRITE(1, "\e[32mUSER undefined, nothing to be done.\n\e[37m");
		return ;
	}
	chdir(ft_cd_join("/Users/", user));
}

void		ft_cd(const t_cmd * const cmd)
{
	char	buffer[8096];

	if (cmd->args[1] == NULL)
	{
		ft_go_home();
		return ;
	}
	ft_memset_ll(buffer, 0, 1012);
	if (getcwd(buffer, 8096) == NULL)
		return ;
	if (ft_move_back(!ft_strncmp(cmd->args[1], "-", 2), buffer))
		return ;
	if (!ft_strncmp(cmd->args[1], "~", 1))
	{
		ft_go_home();
		return ;
	}
	else if (!ft_strncmp(cmd->args[1], "/", 2))
		chdir("/");
	if (chdir(ft_cd_join(buffer, cmd->args[1])) == -1)
	{
		if (chdir(cmd->args[1]) == -1)
			;//WWRITE(1, "cd : no such file or directory\n");
	}
	if (ft_env_for_key("PWD") && getcwd(buffer, 8096))
		ft_change_key_for_value("PWD", buffer);
}
