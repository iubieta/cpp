# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 11:56:56 by iubieta-          #+#    #+#              #
#    Updated: 2026/02/06 23:53:46 by iubieta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -g

SRCS := main.cpp Base.cpp
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
