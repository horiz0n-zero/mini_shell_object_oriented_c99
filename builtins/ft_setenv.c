/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:51:31 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 15:32:56 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_realloc_env(const char *key, const char *value)
{
	extern char	**environ;
	char		**ptr;
	char		**new;
	char		**ptr_new;

	ptr = environ;
	new = malloc(sizeof(char*) * (ft_env_count() + 2));
	ptr_new = new;
	while (*ptr)
	{
		*ptr_new++ = ft_copy(*ptr);
		free(*ptr++);
	}
	*ptr = ft_copy(ft_stc_strjoin(key, "="));
	*ptr_new++ = ft_copy(ft_stc_strjoin(*ptr, value));
	free(*ptr);
	*ptr_new = NULL;
	environ = new;
}

void			ft_change_key_for_value(const char *key, const char *value)
{
	extern char	**environ;
	char		**ptr;
	char		*tmp;

	tmp = NULL;
	ptr = environ;
	while (*ptr)
	{
		if (!ft_strncmp(key, *ptr, ft_strlen(key)))
		{
			free(*ptr);
			tmp = ft_copy(ft_stc_strjoin(key, "="));
			*ptr = ft_copy(ft_stc_strjoin(tmp, value));
			free(tmp);
			break ;
		}
		ptr++;
	}
}

void			ft_setenv(const t_cmd * const cmd)
{
	if (cmd->args[1] == NULL || cmd->args[2] == NULL)
	{
		wwrite(1, "\e[93msetenv VAR [VALUE]\e[37m\n")
		return ;
	}
	if (ft_env_for_key(cmd->args[1]) == NULL)
		ft_realloc_env(cmd->args[1], cmd->args[2]);
	else
		ft_change_key_for_value(cmd->args[1], cmd->args[2]);
	if (cmd->args[1] && !ft_strncmp(cmd->args[1], "PATH", 4))
		ft_typeofpath(NULL, NULL, 42);
}
