/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:28:19 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 16:56:45 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
		return ;
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
	if (!ft_strncmp(cmd->args[1], "~", 1))
	{
		ft_go_home();
		return ;
	}
	else if (!ft_strncmp(cmd->args[1], "/", 2))
		chdir("/");
	if (getcwd(buffer, 8096) == NULL)
		return ;
	if (chdir(ft_cd_join(buffer, cmd->args[1])) == -1)
	{
		if (chdir(cmd->args[1]) == -1)
			write(1, "cd : no such file or directory\n",
				sizeof("cd : no such file or directory\n"));
	}
}
