NAME	= sed_for_losers

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean