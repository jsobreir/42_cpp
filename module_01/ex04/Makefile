CC = c++

SRC = main.cpp

NAME = a.out

FLAGS =  -std=c++98 -g -Wall -Wextra -Werror -o

RED := \033[31m
BOLD_RED := \e[1;31m
GREEN := \033[32m
BLUE := \e[34m
YELLOW := \e[33m
RESET := \033[0m


all: $(SRC)
	$(CC) $(SRC) $(FLAGS) $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

test:
	@echo "$(BOLD_RED)Running Tests...$(RESET)"

	@echo "$(BLUE)----- Test 1 -----$(RESET)"
	@echo "Simple Hello world"
	@echo "Hello world" > test.txt
	@./$(NAME) test.txt world universe
	@echo -n "Hello universe" > expected.txt
	@echo "- result:"
	@diff test.txt.replace expected.txt && \
		echo "$(GREEN)Test Passed!$(RESET)" || \
		echo "$(RED)Test Failed$(RESET)"

	@echo "\n"

	@echo "$(BLUE)----- Test 2 -----$(RESET)"
	@echo "Two lines"
	@echo "Ola o meu nome\ne Joao" > test.txt
	@./$(NAME) test.txt Joao Tiago
	@echo -n "Ola o meu nome\ne Tiago" > expected.txt
	@echo "- result:"
	@diff test.txt.replace expected.txt && \
		echo "$(GREEN)Test Passed!$(RESET)" || \
		echo "$(RED)Test Failed$(RESET)"

	@echo "\n"

	@echo "$(BLUE)----- Test 3 -----$(RESET)"
	@echo "replace spaces"
	@echo "     " > test.txt
	@./$(NAME) test.txt " " "         "
	@echo -n "                                             " > expected.txt
	@echo "- result:"
	@diff test.txt.replace expected.txt && \
		echo "$(GREEN)Test Passed!$(RESET)" || \
		echo "$(RED)Test Failed$(RESET)"

	@echo "\n"

	@echo "$(BLUE)----- Test 4 -----$(RESET)"
	@echo "Inexistent file"
	@rm -rf test.txt expected.txt test.txtx.replace
	@./$(NAME) test.txt Joao Tiago > out
	@echo "Failed to open filetest.txt" > expected.txt	
	@DIFF=$(diff out expected.txt); \
	if [ $$? -eq 0 ]; then \
		echo "$(GREEN)Test Passed!$(RESET)"; \
	else \
		echo "$(RED)Test Failed! test.txt.replace does not exist$(RESET)"; \
	fi
	rm -rf out expected.txt test.txt test.txt.replace

.PHONY: all fclean re