# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 09:34:17 by aurodrig          #+#    #+#              #
#    Updated: 2025/07/11 11:41:24 by aurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
CXX = c++ -fsanitize=address -g
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = main.cpp \
	  BitcoinExchange.cpp 


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