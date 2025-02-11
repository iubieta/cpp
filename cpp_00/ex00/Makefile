# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 23:34:34 by iubieta-          #+#    #+#              #
#    Updated: 2025/02/11 23:34:37 by iubieta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = megaphone

# Compilador y flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Archivos fuente
SRCS = megaphone.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla principal: compila el programa
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpia archivos objeto
clean:
	rm -f $(OBJS)

# Limpia todo (incluyendo el binario)
fclean: clean
	rm -f $(NAME)

# Recompila desde cero
re: fclean all

# No es un archivo físico
.PHONY: all clean fclean re

