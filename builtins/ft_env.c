/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:42:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 15:35:17 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void ft_remove_env(void)
{
	extern char **environ;

	while (*environ)
		free(*environ++);
}

static void ft_print(void)
{
	extern char		**environ;
	char			    **ptr;

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
	else if (!ft_strncmp(cmd->args[1], "-save", 5))
		ft_create_env();
	ft_typeofpath(NULL, NULL, 42);
}
