NAME = MutantStack
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++
PATH_OBJS = ./objects/

SRCS = main.cpp
OBJS = $(patsubst %.cpp,$(PATH_OBJS)%.o,$(SRCS))

all: $(NAME)

run: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $^ -o $(NAME)

$(PATH_OBJS)%.o: %.cpp MutantStack.hpp
	@mkdir -p $(PATH_OBJS)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(PATH_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
