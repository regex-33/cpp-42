NAME = Polymorphism 

SRC_DIR = src/
SRC = $(wildcard $(SRC_DIR)*.cpp)
OBJ = $(SRC:.cpp=.o)
vpath = %.h ./Includes
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I ./Includes

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
