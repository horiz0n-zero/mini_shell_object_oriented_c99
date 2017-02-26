/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:57:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 19:08:52 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_create_env(void)
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

void			ft_check_env(void)
{
	extern char	**environ;

	if (environ == NULL || *environ == NULL)
		ft_create_env();
}
