# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 18:26:22 by iubieta-          #+#    #+#              #
#    Updated: 2026/02/24 18:27:41 by iubieta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bitcoinExchange

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

SRCS := main.cpp 
OBJS := $(SRCS:%.cpp=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf *.gch

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
