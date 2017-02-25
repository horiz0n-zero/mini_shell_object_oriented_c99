# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 16:01:32 by afeuerst          #+#    #+#              #
#    Updated: 2017/02/25 16:15:32 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=shell

FLAGS = -O2 -fsanitize=address -g

all:
	make -j $(NAME)

$(NAME):
	clang -I. $(FLAGS) $(shell find . -type f | grep "\.c") -o $(NAME)

clean:
	@echo "nothing to do"

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
