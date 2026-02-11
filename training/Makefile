# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 16:56:29 by fpaglia           #+#    #+#              #
#    Updated: 2026/02/11 17:01:22 by fpaglia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98
FLAGS = -g3 -std=c++98

# FILES = megaphone.cpp
FILES = test.cpp Trial.cpp Trial.sum.cpp InitLst.cpp \
		Setter.cpp Compare.cpp InstCount.cpp


NAME = training

$(NAME):
	$(CC) $(FLAGS) $(FILES) -o $@ 

.PHONY: fclean

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

run: re
	./$(NAME)
