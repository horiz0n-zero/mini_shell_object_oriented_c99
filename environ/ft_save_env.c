/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:57:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/27 15:34:29 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_create_env(void)
{
	extern char	**environ;
	char		**ptr;
	char		buffer[8096];

	ft_memset_ll(buffer, 0, 1012);
	ptr = malloc(sizeof(char*) * 6);
	environ = ptr;
	*ptr++ = ft_copy(ft_stc_strjoin("PWD=", getcwd(buffer, 8096)));
	*ptr++ = ft_copy("SHELL=");
	*ptr++ = ft_copy("PATH=");
	*ptr++ = ft_copy("USER=");
	*ptr++ = ft_copy("TERM=xterm-256color");
	*ptr = NULL;
}

size_t ft_env_count(void)
{
	extern char **environ;
	char        **ptr;
	size_t      count;

	count = 1;
	ptr = environ;
	while (*ptr && **ptr)
	{
		count++;
		ptr++;
	}
	return (count);
}

static char *ft_env_fill_key(const char *src)
{
	char			*ptr;
	char			*str;

	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	str = ptr;
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (str);
}

static void ft_env_copy(void)
{
	extern char **environ;
	char 				**env;
	char 				**ptr;
	char				**new;

	ptr = (char**)malloc(sizeof(char*) * ft_env_count());
	new = ptr;
	env = environ;
	while (*env && **env)
		*ptr++ = ft_env_fill_key(*env++);
	*ptr = NULL;
	environ = new;
}

void			ft_save_env(void)
{
	extern char	**environ;

	if (environ == NULL || *environ == NULL)
		ft_create_env();
	else
		ft_env_copy();
}
