NAME = diamond_trap
COMPILER = c++ -std=c++98
COMPILER_FLAGS = -Wall -Wextra -Werror

SOURCES =	main.cpp \
			ClapTrap.cpp \
			FragTrap.cpp \
			ScavTrap.cpp \
			DiamondTrap.cpp

OBJCECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(SOURCES)
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -rf $(OBJCECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re