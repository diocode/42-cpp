# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 13:01:56 by digoncal          #+#    #+#              #
#    Updated: 2023/08/03 13:01:56 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
DEPS =

SRC = zombie.cpp zombieHorde.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = zombieHorde

all: $(NAME)
$(NAME): $(OBJ) $(DEPS)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm $(OBJ)
fclean: clean
	@rm $(NAME)
re: fclean all