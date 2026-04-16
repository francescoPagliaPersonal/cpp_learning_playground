# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 16:56:29 by fpaglia           #+#    #+#              #
#    Updated: 2026/04/16 12:39:53 by fpaglia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Werror -Wextra  -std=c++98 -MMD -MP
INCLUDES = -Iinclude
PREPR ?=

DBG ?= 0
ifeq ($(DBG),1)
	FLAGS += -g3 -Wno-unused
	PREPR += -D DEBUG=1
endif

SHW ?= 0
ifeq ($(SHW),1)
	FLAGS += -Wshadow-all 
endif

BLD_DIR := build
SRC_DIR := source
ARGS ?= 

FILES = main.cpp
		

NAME = template


SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(patsubst $(SRC_DIR)/%, $(BLD_DIR)/%, $(SRC:%.cpp=%.o))
DEPS = $(OBJ:.o=.d)

$(NAME): $(OBJ)
	$(CC) $(PREPR) $(FLAGS) $(INCLUDES) $(OBJ) -o $@ 

$(BLD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(dir $@)
	$(CC) $(PREPR) $(FLAGS) $(INCLUDES) -o $@ -c $<

-include $(DEPS)

.PHONY: clean fclean re all run

clean:
	rm -rf $(BLD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

all: $(NAME)

run: re
	./$(NAME) $(ARGS)

dbg: fclean
	$(MAKE) DBG=1
	./$(NAME) $(ARGS)

shw: fclean
	$(MAKE) SHW=1
	./$(NAME) $(ARGS)
