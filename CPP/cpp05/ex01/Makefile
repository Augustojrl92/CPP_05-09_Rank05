# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 22:26:00 by aurodrig          #+#    #+#              #
#    Updated: 2025/07/15 18:56:00 by aurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form
CXX = c++ -fsanitize=address -g
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = main.cpp \
	  Bureaucrat.cpp \
	  Form.cpp
OBJ =  $(SRC:.cpp=.o)

$(NAME): ${OBJ}
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean