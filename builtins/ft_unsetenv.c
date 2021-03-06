/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:50:56 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 19:33:22 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_remove_value(const char *key);

void			ft_remove_env_for_key(const char *key)
{
	if (ft_env_for_key(key) == NULL)
		WWRITE(1, "\e[32mAny env reference found, nothing to be done.\n\e[37m")
	else
		ft_remove_value(key);
}

static void		ft_remove_value(const char *key)
{
	extern char	**environ;
	char		**ptr;
	char		**new;
	char		**new_ptr;

	ptr = environ;
	new = malloc(sizeof(char*) * ft_env_count());
	new_ptr = new;
	while (*ptr)
	{
		if (!ft_strncmp(key, *ptr, ft_strlen(key)))
		{
			free(*ptr);
			ptr++;
			continue ;
		}
		*new_ptr++ = ft_copy(*ptr);
		free(*ptr++);
	}
	*new_ptr = NULL;
	environ = new;
}

void			ft_unsetenv(const t_cmd * const cmd)
{
	if (cmd->args[1] == NULL)
	{
		WWRITE(1, "\e[33musage : unsetenv VAL\n\e[37m")
		return ;
	}
	if (ft_env_for_key(cmd->args[1]) == NULL)
		WWRITE(1, "\e[31munsetenv : reference not found in env, nothing done.\e[37m\n")
	else
		ft_remove_value(cmd->args[1]);
	ft_typeofpath(NULL, NULL, 42);
}
