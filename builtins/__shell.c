/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __shell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:12:31 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/26 16:30:44 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_usage_shell(void)
{
	write(1, "\e[94musage : shell\n", sizeof("\e[94musage : shell\n"));
	write(1, "-- restrict\n-- unrestrict\n-- reload\n", 
			sizeof("-- restrict\n-- unrestrict\n-- reload\n"));
	write(1, "\e[37m", sizeof("\e[37m"));
}

static void	ft_restrict(void)
{
	write(1, "\e[91menter in \e[31mrestrict mode\n\e[37m",
			sizeof("\e[91menter in \e[31mrestrict mode\n\e[37m"));
}

static void	ft_unrestrict(void)
{
	write(1, "\e[32mexiting \e[92mrestrict mode\n\e[37m",
			sizeof("\e[31exiting \e[91mrestrict mode\n\e[37m"));
}

static void	ft_reload(void)
{

}

void		ft_shell(const t_cmd * const cmd)
{
	if (cmd->args[1] == NULL)
		ft_usage_shell();
	else if (!ft_strncmp(cmd->args[1], "restrict", 8))
		ft_restrict();
	else if (!ft_strncmp(cmd->args[1], "unrestrict", 10))
		ft_unrestrict();
	else if (!ft_strncmp(cmd->args[1], "reload", 6))
		ft_reload();
	else
		ft_usage_shell();
}
