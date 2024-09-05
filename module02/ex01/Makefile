NAME = fixed_base2

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRCS = main.cpp \
		Fixed.cpp

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
