CC = g++

SRC = megaphone.cpp

NAME = megaphone

FLAGS =  -std=c++98 -Wall -Wextra -Werror -o

all: $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re