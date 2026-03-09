NAME = bureaucrat

CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
       ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp Intern.cpp
	   
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re