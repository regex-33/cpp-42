SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I./ 

NAME = main

all: $(NAME) 

$(NAME): $(OBJ) 
	@$(CC) $(CPPFLAGS) $(OBJ) -o $@
	@echo "\n\033[32m[+] Compiled $(NAME) successfully!\033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
