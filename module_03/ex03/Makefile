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
CXXFLAGS = -Wall -Werror -Wextra -Wshadow -std=c++98
DEPS =

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = diamondtrap

all: $(NAME)
$(NAME): $(OBJ) $(DEPS)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm $(OBJ)
fclean: clean
	@rm $(NAME)
re: fclean all