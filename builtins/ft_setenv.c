/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:51:31 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 19:44:46 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_realloc_env__(const char *val, const char *value, size_t n)
{
	extern char	**environ;
	char		**ptr;
	char		**new;
	char		**s_new;

	ptr = environ;
	s_new = malloc(sizeof(char*) * (n + 2));
	new = s_new;
	while (*ptr && **ptr)
	{
		while (**ptr)
			**new++ = **ptr++;
		ptr++;
		new++;
	}
	environ = s_new;
	(void)val;
	(void)value;
}

static void		ft_realloc_env(const char *val, const char *value)
{
	extern char	**environ;
	char		**ptr;
	size_t		count;

	count = 0;
	ptr = environ;
	while (*ptr && **ptr)
	{
		ptr++;
		count++;
	}
	ft_realloc_env__(val, value, count);
}

static uint32_t	ft_changeif(const char *var, const char *value)
{
	extern char	**environ;
	char		**ptr;
	char		*copy;
	char		*tmp;

	tmp = NULL;
	copy = NULL;
	ptr = environ;
	while (*ptr && **ptr)
	{
		if (!ft_strncmp(*ptr, var, ft_strlen(var)))
		{
			tmp = ft_copy(ft_stc_strjoin(var, "="));
			copy = ft_copy(ft_stc_strjoin(tmp, value));
			free(tmp);
			*ptr = copy;
			return (1);
		}
	}
	return (0);
}

void			ft_setenv(const t_cmd * const cmd)
{
	if (cmd->args[1] == NULL || cmd->args[2] == NULL)
	{
		wwrite(1, "\e[93msetenv VAR [VALUE]\e[37m\n")
		return ;
	}
	if (!ft_changeif(cmd->args[1], cmd->args[2]))
	{
		ft_realloc_env(cmd->args[1], cmd->args[2]);
	}
}
