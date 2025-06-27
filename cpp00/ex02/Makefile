# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 16:17:14 by jaoh              #+#    #+#              #
#    Updated: 2025/06/27 13:32:32 by jaoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= GBU

CC		= g++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= Account.cpp tests.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -I .

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean