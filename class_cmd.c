/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:17:44 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 23:04:01 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>
static char						*ft_ccopy(const char *str)
{
	char						*s;
	char						*ptr;

	s = malloc(ft_strlen(str) + 1);
	ptr = s;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (s);
}

// self == description de la class,
// le buffer
// la precedente commande;
void							*ft_ctor(const void * const self, ...)
{
	struct s_cmd				*new;
	va_list						args;
	char						*buffer;

	va_start(args, self);
	buffer = va_arg(args, char*);
	new = malloc(sizeof(struct s_cmd));
	new->__class = self;
	new->copy = ft_ccopy(buffer);
	new->args = ft_strsplit(buffer, ' ');
	new->last = va_arg(args, void*);
	new->next = NULL;
	return (new);
}

void							ft_dtor(void * const self)
{
	struct s_cmd				*cmd;

	cmd = (struct s_cmd*)self;
	while (*cmd->args)
		free(*cmd->args++);
	free(cmd->copy);
	free(self);
}
