CC = g++

SRC = main.cpp Harl.cpp

NAME = harl

FLAGS =  -std=c++98 -g -Wall -Wextra -Werror -o

all: $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re