NAME	= harl

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:.cpp=.o)
INC		= -I ./

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean