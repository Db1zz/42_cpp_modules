NAME = PmergeMe
COMPILER = c++ -std=c++98
COMPILER_FLAGS = -Wall -Wextra -fsanitize=address -g #-Werror

SOURCES =	main.cpp	\
			PmergeMe.cpp	\
			ParserError.cpp	\
			parser.cpp	\

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
