# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 16:01:32 by afeuerst          #+#    #+#              #
#    Updated: 2017/03/01 19:26:56 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

FLAGS = -fshort-enums -Wall -Wextra -Werror -O2
#-fsanitize=address -g

C_SOURCES = $(shell find . -type f | grep "\.c")
O_SOURCES = $(C_SOURCES:.c=.o)

PRINTF = printf "\e[94m%-30s  \e[96m-->>  \e[92m%-30s\n" $< $@
WHITE = printf "\e[37m"

all:
	printf "\e[34mcompiling Minishell ...\n"
	make -j $(NAME)
	$(WHITE)

$(NAME): $(O_SOURCES)
	clang $(O_SOURCES) -o $(NAME)
	printf "\e[32mshell is now available\n"

%.o: %.c
	clang -I. $(FLAGS) -c $< -o $@ && $(PRINTF)

clean:
	rm -rf $(O_SOURCES)
	printf "\e[31mcleaning done\n"
	$(WHITE)

fclean: clean
	printf "\e[31mremoving shell\n"
	rm -rf $(NAME)
	$(WHITE)

re: fclean all

.PHONY: all $(NAME) clean fclean re
.SILENT:
