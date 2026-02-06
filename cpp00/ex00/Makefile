# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 16:56:29 by fpaglia           #+#    #+#              #
#    Updated: 2026/02/03 14:02:12 by fpaglia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP

DBG ?= 0
ifeq ($(DBG),1)
	FLAGS += -g3
endif

BLD_DIR := build
SRC_DIR := .
ARGS ?= 

NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=$(BLD_DIR)/%.o)
DEPS = $(OBJ:.o=.d)
-include $(DEPS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@ 

$(BLD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: clean fclean re all run

clean:
	rm -rf $(BLD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

all: $(NAME)

run: all
	./$(NAME) $(ARGS)

dbg:
	$(MAKE) DBG=1
	./$(NAME) $(ARGS)