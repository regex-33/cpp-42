NAME = Polymorphism 

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDES = -I includes

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I ./

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re