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

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
NAME = harl

all: $(NAME)
$(NAME): $(OBJ) $(DEPS)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm $(OBJ)
fclean: clean
	@rm $(NAME)
re: fclean all