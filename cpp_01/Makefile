# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 20:28:37 by iubieta-          #+#    #+#              #
#    Updated: 2025/06/22 20:39:23 by iubieta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -g

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
