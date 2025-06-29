NAME	= zombie

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

INC_PATH	= ./includes/
INC			= -I $(INC_PATH)

SRC_PATH	= ./srcs/
SRC			=	Zombie.cpp \
				zombieHorde.cpp \
				main.cpp			
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= ./objs/
OBJS		= $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean