# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 11:56:56 by iubieta-          #+#    #+#              #
#    Updated: 2025/10/13 18:54:21 by iubieta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

SRCS_DIR := .
OBJS_DIR := ./objs

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean :
	rm -rf $(OBJS_DIR)
	rm -rf *.gch

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
