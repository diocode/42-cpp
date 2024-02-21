# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal                                   +#+  +:+       +#+         #
#    <digoncal@student.42porto.com>               +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
DEPS =

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = fragtrap

all: $(NAME)
$(NAME): $(OBJ) $(DEPS)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm $(OBJ)
fclean: clean
	@rm $(NAME)
re: fclean all