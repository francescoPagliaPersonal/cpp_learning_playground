# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 16:56:29 by fpaglia           #+#    #+#              #
#    Updated: 2026/02/05 11:33:35 by fpaglia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98
FLAGS = -g3 -std=c++98

# FILES = megaphone.cpp
FILES = main.cpp PhoneBook.class.cpp Contact.class.cpp Errors.cpp

NAME = phonebook

$(NAME):
	$(CC) $(FLAGS) $(FILES) -o $@ 

.PHONY: fclean

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

run: re
	./$(NAME)
