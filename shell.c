/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:00:37 by afeuerst          #+#    #+#             */
/*   Updated: 2017/03/01 13:15:45 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const struct s_class	g_desc_cmd =
{
	sizeof(struct s_cmd), ft_ctor, ft_dtor
};

static const void * const	g_ptr_cmd = &g_desc_cmd;

static void					ft_launch_command(const char *buffer, t_cmd **cmds)
{
	extern t_info			g_info;

	*cmds = (*(t_class*)g_ptr_cmd).ctor(g_ptr_cmd, buffer, *cmds);
	if (ft_builtins(*cmds))
	{
		if (!g_info.restricted)
			ft_start_command(*cmds);
		else
		{
			if (!ft_strncmp("ls", *(*cmds)->args, 2))
				ft_start_command(*cmds);
			else
				wwrite(1, "\e[31mCommand denied\n\e[37m")
		}
	}
	//ft_fx(click_start)
}

int							main(void)
{
	char					buffer[CHAR_MAX_LINE];
	int						ret;
	struct s_cmd			*cmds;

	cmds = NULL;
	ret = 0;
	ft_memset(buffer, 0, CHAR_MAX_LINE);
	clear
	ft_init();
	while (1 | (ret = read(0, buffer, CHAR_MAX_LINE)))
	{
		if (ret)
		{
			if ((buffer + --ret) != buffer)
				ft_launch_command(buffer, &cmds);
			enter_mode
			ft_memset(buffer, 0, CHAR_MAX_LINE);
			ret = 0;
		}
	}
}
