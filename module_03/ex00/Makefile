CC = c++

SRC = main.cpp ClapTrap.cpp

NAME = claptrap

FLAGS =  -std=c++98 -g -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)
fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re