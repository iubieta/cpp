# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 14:13:53 by iubieta-          #+#    #+#              #
#    Updated: 2026/02/15 17:09:28 by iubieta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

SRCS := main.cpp Span.cpp
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
