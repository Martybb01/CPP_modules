NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = main.cpp \
	PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
