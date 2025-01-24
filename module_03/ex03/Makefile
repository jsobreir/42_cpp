CC = c++

SRC = main.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp

NAME = diamondtrap

FLAGS =  -std=c++98 -g -Wall -Wextra -Werror -Wshadow -o

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re