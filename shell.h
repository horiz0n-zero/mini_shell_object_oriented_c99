/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:57:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/02/25 23:03:57 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <dirent.h>
# include <errno.h>

// a supr :
#include <string.h>
#include <stdio.h>

typedef struct	s_class
{
	size_t		size;
	void		*(*ctor)(const void * const, ...);
	void		(*dtor)(void * const);
}				t_class;

typedef struct	s_cmd
{
	const void	*__class;
	char		**args;
	char		*copy;
	void		*next;
	void		*last;
}					t_cmd;
void			*ft_ctor(const void * const self, ...);
void			ft_dtor(void * const self);

# define clear write(1, "\e[0;0H\e[2J\e[37m$>", sizeof("\e[0;0H\e[2J\e[37m$>"));
# define enter_mode write(1, "\e[37m$>", sizeof("\e[37m$>"));

/* fonctions d'execution */
void ft_start_command(const t_cmd * const cmd);

/* fonctions d'environement */
typedef struct s_board
{
	char				*path;
	char				**content;
	struct s_board *next;
}							t_board;
t_board *ft_get_bin_board(void); // recupere tout les binares indiquer par le path

char		*ft_env_for_key(const char *key);

char			**ft_strsplit(char *s, int (*f)(int));
int ft_isspace(const int c);
int ft_isdoublepoint(const int c);

/* mem functions in utility : */
void			ft_memset_ll(void * const ptr, const uint64_t val, size_t len);
void			ft_memset(void * const ptr, const uint8_t val, size_t len);

/* string functions form utility */
size_t			ft_strlen(const char *str);
char			*ft_stc_strjoin(const char *s1, const char *s2);
char			*ft_copy(const char *str);
#endif