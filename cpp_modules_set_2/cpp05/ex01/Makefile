# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 15:03:44 by amalbrei          #+#    #+#              #
#    Updated: 2023/08/11 20:31:48 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
RM = rm -rf
SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	

re: fclean all

.PHONY: all clean fclean re