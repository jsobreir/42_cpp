CC = g++

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

NAME = zombie

FLAGS =  -std=c++98 -g -Wall -Wextra -Werror -o

all: $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re