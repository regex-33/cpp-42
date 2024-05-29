SRC = main.cpp zombieHorde.cpp Zombie.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I ./

NAME = zombie

all: $(NAME) 

$(NAME): $(OBJ) 
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME) > /dev/null 2>&1
	@$(RM) $(OBJ) > /dev/null 2>&1
	@echo "\n\033[32m[+] Compiled $(NAME) successfully!\033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
