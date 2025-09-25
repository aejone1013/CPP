NAME = zombie

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp newZombie.cpp randomChump.cpp	main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re