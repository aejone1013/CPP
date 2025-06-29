NAME = ptrref

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean