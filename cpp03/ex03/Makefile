NAME = DiamondTrap 

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)
INCLUDES = -I includes

vpath %.cpp srcs
vpath %.hpp includes

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDES) 

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re