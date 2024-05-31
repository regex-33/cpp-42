NAME = Polymorphism 

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp brain.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDES = -I includes

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 -I ./ -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
