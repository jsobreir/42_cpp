CC = c++

SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp

NAME = fragtrap

FLAGS =  -std=c++98 -g -Wall -Wextra -Werror -o

all: $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re