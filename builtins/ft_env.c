/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:42:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/28 16:36:05 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			ft_usage(void)
{
	wwrite(1, "\e[34musage : env\n-i \t\t-- remove the environement\n")
	wwrite(1, "-u [VALUE] \t-- remove VALUE reference in environement\n")
	wwrite(1, "-new \t\t-- create a new simple env.\n\e[37m")
}

static void			ft_remove_env(void)
{
	extern char		**environ;

	while (*environ)
		free(*environ++);
}

static void			ft_print(void)
{
	extern char		**environ;
	char			**ptr;

	ptr = environ;
	while (*ptr)
	{
		write(1, *ptr, ft_strlen(*ptr));
		write(1, "\n", 1);
		ptr++;
	}
}

void				ft_env(const t_cmd * const cmd)
{
	if (cmd->args[1] == NULL)
		ft_print();
	else if (!ft_strncmp(cmd->args[1], "-i", 3))
		ft_remove_env();
	else if (!ft_strncmp(cmd->args[1], "-new", 5))
		ft_create_env();
	else if (!ft_strncmp(cmd->args[1], "-u", 3) && cmd->args[2])
		ft_remove_env_for_key(cmd->args[2]);
	else
		ft_usage();
	ft_typeofpath(NULL, NULL, 42);
}
