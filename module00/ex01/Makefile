NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		phonebook.cpp \
		contact.cpp

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@$(RM)  $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
