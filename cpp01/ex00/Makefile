NAME = ex00
COMPILER = c++ -std=c++98
COMPILER_FLAGS = -Wall -Wextra -Werror
INCLUDE_FLAGS = -I include

SOURCES =	newZombie.cpp \
			main.cpp	\
			randomChump.cpp	\
			Zombie.cpp

OBJCECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(SOURCES)
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCES) $(INCLUDE_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJCECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re